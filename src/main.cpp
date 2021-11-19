// # Liella Program Entrance
// @PENGUINLIONG
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "liella/spv-instr.hpp"
#include "liella/collect-id-refs.hpp"

std::vector<uint32_t> load_spv(const std::string& path) {
  std::ifstream is(path, std::ios::in | std::ios::ate | std::ios::binary);
  assert(is);
  size_t size = is.tellg();
  is.seekg(0, std::ios::beg);
  std::vector<uint32_t> spv;
  if ((size & (sizeof(uint32_t) - 1)) != 0) { return {}; }
  spv.resize(size / sizeof(uint32_t));
  is.read((char*)spv.data(), size);
  return spv;
}
void store_spv(const std::string& path, const std::vector<uint32_t> spv) {
  std::ofstream os(path.c_str(),
    std::ios::out | std::ios::trunc | std::ios::binary);
  os.write((const char*)spv.data(), spv.size() * sizeof(uint32_t));
}



using namespace liella;

typedef uint32_t InstrIdx;

struct CodeBlock {
  spv::Id label_id;
  InstrIdx beg;
  InstrIdx end;
  std::vector<spv::Id> branch_target_ids;
};
struct IterVar {
  spv::Id var;
  uint32_t stride;
};
struct Loop {
  spv::Id merge_block;
  spv::Id continue_block;
  std::vector<spv::Id> body_blocks;
  spv::LoopControlMask loop_ctrl;
  std::vector<IterVar> itervars;
};
struct Context {
  // Common properties filled in `apply`.
  const std::vector<Instruction>* instrs;
  const Instruction& get_instr_by_idx(InstrIdx idx) const {
    return instrs->at(idx);
  }
  template<typename TOp>
  bool try_parse_instr(const Instruction& instr, TOp& out) {
    if (instr.opcode != TOp::OP) { return false; }
    out = TOp::parse(instr.iter());
    return true;
  }
  template<typename TOp>
  bool try_parse_instr_by_idx(InstrIdx idx, TOp& out) {
    return try_parse_instr(get_instr_by_idx(idx), out);
  }

  // Provided by `ExprExtractor`.
  std::map<spv::Id, InstrIdx> instr_idx_by_result_id;
  const Instruction& get_instr_by_id(spv::Id id) const {
    return get_instr_by_idx(instr_idx_by_result_id.at(id));
  }
  template<typename TOp>
  bool try_parse_instr_by_id(spv::Id id, TOp& out) {
    return try_parse_instr(get_instr_by_id(id), out);
  }

  // Provided by `CodeBlockExtractor`.
  std::map<spv::Id, CodeBlock> code_block_by_label_id;
  std::map<InstrIdx, spv::Id> label_id_by_loop_merge_idx;
  const CodeBlock& get_code_block_by_label_id(spv::Id id) const {
    return code_block_by_label_id.at(id);
  }
  const CodeBlock& get_code_block_by_loop_merge_idx(InstrIdx loop_merge_idx) const {
    spv::Id label_id = label_id_by_loop_merge_idx.at(loop_merge_idx);
    return get_code_block_by_label_id(label_id);
  }

  // Provided by `LoopExtractor`.
  std::map<spv::Id, Loop> loop_by_loop_merge_idx;
  const Loop& get_loop_by_idx(InstrIdx idx) const {
    return loop_by_loop_merge_idx.at(idx);
  }

  // Provided by `IdDependencyExtractor`.
  std::vector<std::vector<spv::Id>> dependencies_by_instr_idx;
  const std::vector<spv::Id>& get_instr_dependencies(InstrIdx idx) {
    return dependencies_by_instr_idx[idx];
  }
};

struct SpirvVisitor {
  friend struct SpirvPass;
private:
  // Assigned in `with_visitor`.
  Context* ctxt_;

  // Assigned before every invocation to `visit`.
  InstrIdx idx_;
  const Instruction* instr_;

protected:
  // Utility funcitons for `visit()` to fetch the current visited instruction.
  inline InstrIdx idx() const { return idx_; }
  inline const Instruction& instr() const { return *instr_; }
  inline spv::Op opcode() const { return instr_->opcode; }
  inline OperandIterator operands() const { return instr_->iter(); }
  inline const Context& ctxt() const { return *ctxt_; }
  inline Context& ctxt() { return *ctxt_; }
  inline const std::vector<Instruction>& instrs() const {
    return *ctxt_->instrs;
  }
 
public:
  // The user should implement this.
  virtual void visit() = 0;
};
// Independent visitors are bundled into a pass.
struct SpirvPass : public SpirvVisitor {
private:
  Context* ctxt_;
  std::vector<SpirvVisitor*> visitors_;

  inline void apply_(
    const std::vector<Instruction>& instrs,
    uint32_t beg,
    uint32_t end
  ) {
    assert(beg <= end);
    assert(end <= instrs.size());
    ctxt_->instrs = &instrs;
    for (uint32_t i = beg; i < end; ++i) {
      idx_ = i;
      instr_ = &instrs[i];
      visit();
    }
  }

public:
  SpirvPass(Context& ctxt) : ctxt_(&ctxt), visitors_() {}

  SpirvPass& with_visitor(SpirvVisitor& visitor) {
    visitor.ctxt_ = ctxt_;
    visitors_.emplace_back(&visitor);
    return *this;
  }

  virtual void visit() override final {
    for (auto& visitor : visitors_) {
      visitor->idx_ = idx_;
      visitor->instr_ = instr_;
      visitor->visit();
    }
  }

  inline void apply(const std::vector<Instruction>& instrs) {
    apply_(instrs, 0, instrs.size());
  }
  inline void apply_ranged(
    const std::vector<Instruction>& instrs,
    uint32_t beg,
    uint32_t end
  ) {
    apply_(instrs, beg, end);
  }
};

// -----------------------------------------------------------------------------

struct ExprExtractor : public SpirvVisitor {
  virtual void visit() override final {
    bool has_result = false;
    bool has_result_ty = false;
    spv::HasResultAndType(opcode(), &has_result, &has_result_ty);
    if (has_result) {
      auto it = operands();
      if (has_result_ty) {
        spv::Id result_ty_id = it.id();
        spv::Id result_id = it.id();
        ctxt().instr_idx_by_result_id[result_id] = idx();
      } else {
        spv::Id result_id = it.id();
        ctxt().instr_idx_by_result_id[result_id] = idx();
      }
    }
  }
};

struct OpLabel {
  static constexpr spv::Op OP = spv::OpLabel;
  spv::Id result_id;

  static OpLabel parse(OperandIterator it) {
    OpLabel out {};
    out.result_id = it.id();
    return out;
  }
};
struct OpBranch {
  static constexpr spv::Op OP = spv::OpBranch;
  spv::Id target_label;

  static OpBranch parse(OperandIterator it) {
    OpBranch out {};
    out.target_label = it.id();
    return out;
  }
};
struct OpBranchConditional {
  static constexpr spv::Op OP = spv::OpBranchConditional;
  spv::Id condition;
  spv::Id true_label;
  spv::Id false_label;

  static OpBranchConditional parse(OperandIterator it) {
    OpBranchConditional out {};
    out.condition = it.id();
    out.true_label = it.id();
    out.false_label = it.id();
    return out;
  }
};

struct CodeBlockExtractor : public SpirvVisitor {
  uint32_t cur_blk_label_id;

  CodeBlock& cur_blk() {
    return ctxt().code_block_by_label_id[cur_blk_label_id];
  }
  void begin_blk(spv::Id label_id) {
    assert(cur_blk_label_id == 0);
    cur_blk_label_id = label_id;
    cur_blk().label_id = label_id;
    cur_blk().beg = idx();
  }
  void end_blk() {
    assert(cur_blk_label_id != 0);
    cur_blk().end = idx() + 1;
    cur_blk_label_id = 0;
  }
  virtual void visit() override final {
    switch (opcode()) {
    case spv::OpLabel:
    {
      OpLabel label {};
      if (!ctxt().try_parse_instr(instr(), label)) { return; }
      begin_blk(label.result_id);
      break;
    }
    case spv::OpLoopMerge:
    {
      ctxt().label_id_by_loop_merge_idx[idx()] = cur_blk_label_id;
      break;
    }
    case spv::OpBranch:
    {
      OpBranch branch {};
      if (!ctxt().try_parse_instr(instr(), branch)) { return; }
      cur_blk().branch_target_ids.emplace_back(branch.target_label);
      end_blk();
      break;
    }
    case spv::OpBranchConditional:
    {
      OpBranchConditional branch_conditional {};
      if (!ctxt().try_parse_instr(instr(), branch_conditional)) { return; }
      cur_blk().branch_target_ids.emplace_back(branch_conditional.true_label);
      cur_blk().branch_target_ids.emplace_back(branch_conditional.false_label);
      end_blk();
      break;
    }
    case spv::OpSwitch: std::abort(); break;// TODO:
    case spv::OpReturn:
    case spv::OpReturnValue:
    case spv::OpKill:
    case spv::OpUnreachable:
    {
      end_blk();
      break;
    }
    default: break;
    }
  }
};

// -----------------------------------------------------------------------------

struct OpIAdd {
  static constexpr spv::Op OP = spv::OpIAdd;
  spv::Id result_ty_id;
  spv::Id result_id;
  spv::Id operand1;
  spv::Id operand2;

  static OpIAdd parse(OperandIterator it) {
    OpIAdd out {};
    out.result_ty_id = it.id();
    out.result_id = it.id();
    out.operand1 = it.id();
    out.operand2 = it.id();
    return out;
  }
};
struct OpConstant {
  static constexpr spv::Op OP = spv::OpConstant;
  spv::Id result_ty_id;
  spv::Id result_id;
  int64_t literal; // which constains a value of `int32_t` or `uint32_t`.

  static OpConstant parse(OperandIterator it) {
    OpConstant out {};
    out.result_ty_id = it.id();
    out.result_id = it.id();
    out.literal = it.u32();
    return out;
  }
};
struct OpLoad {
  static constexpr spv::Op OP = spv::OpLoad;
  spv::Id result_ty_id;
  spv::Id result_id;
  spv::Id pointer;
  spv::MemoryAccessMask memory_operand;

  static OpLoad parse(OperandIterator it) {
    OpLoad out {};
    out.result_ty_id = it.id();
    out.result_id = it.id();
    out.pointer = it.id();
    out.memory_operand = it.ate() ? spv::MemoryAccessMaskNone : (spv::MemoryAccessMask)it.u32();
    return out;
  }
};
struct OpStore {
  static constexpr spv::Op OP = spv::OpStore;
  spv::Id pointer;
  spv::Id object;
  spv::MemoryAccessMask memory_operand;

  static OpStore parse(OperandIterator it) {
    OpStore out {};
    out.pointer = it.id();
    out.object = it.id();
    out.memory_operand = it.ate() ? spv::MemoryAccessMaskNone : (spv::MemoryAccessMask)it.u32();
    return out;
  }
};

// Apply this only to instruction in continue blocks.
struct IterVarExtractor : public SpirvVisitor {
  std::vector<IterVar>* itervars;
  IterVarExtractor(std::vector<IterVar>& itervars) : itervars(&itervars) {}

  virtual void visit() override final {
    OpStore store;
    if (!ctxt().try_parse_instr(instr(), store)) { return; }

    OpIAdd iadd;
    if (!ctxt().try_parse_instr_by_id(store.object, iadd)) { return; }

    OpConstant constant;
    uint32_t stride;
    spv::Id load_id;
    if (ctxt().try_parse_instr_by_id(iadd.operand1, constant)) {
      stride = constant.literal;
      load_id = iadd.operand2;
    } else if (ctxt().try_parse_instr_by_id(iadd.operand2, constant)) {
      stride = constant.literal;
      load_id = iadd.operand1;
    } else {
      return;
    }

    OpLoad load;
    if (!ctxt().try_parse_instr_by_id(load_id, load)) { return; }
    if (store.pointer != load.pointer) { return; }

    IterVar out {};
    out.var = store.pointer;
    out.stride = stride;
    itervars->emplace_back(std::move(out));
  }
};

struct OpLoopMerge {
  static constexpr spv::Op OP = spv::OpLoopMerge;
  spv::Id merge_block;
  spv::Id continue_block;
  spv::LoopControlMask loop_ctrl;

  static OpLoopMerge parse(OperandIterator it) {
    OpLoopMerge out {};
    out.merge_block = it.id();
    out.continue_block = it.id();
    out.loop_ctrl = (spv::LoopControlMask)it.u32();
    return out;
  }
};

struct LoopExtractor : public SpirvVisitor {
  // Returns true if a direct or indirect dependency of `blk_stack.back()` is
  // `target_label_id` which is the id of the block the loop merge instruction
  // is in.
  bool collect_ring_blks_impl(
    std::set<spv::Id>& body_blks,
    std::vector<spv::Id>& blk_stack
  ) {
    bool in_ring = false;

    size_t depth = blk_stack.size();
    const CodeBlock& blk = ctxt().get_code_block_by_label_id(blk_stack.back());
    blk_stack.resize(depth + 1);
    for (spv::Id branch_target_id : blk.branch_target_ids) {
      // We have reached back to the loop merge instruction, which means we have
      // discovered a ring in the execution graph, expressions in this ring
      // should be analyzed for references to the iteration variables.
      if (branch_target_id == blk_stack.front()) {
        // Don't register the loop merge block itself.
        return true; // Direct edge to a loop merge block.
      }
      blk_stack[depth] = branch_target_id;
      bool child_in_ring = collect_ring_blks_impl(body_blks, blk_stack);
      if (child_in_ring) {
        body_blks.emplace(branch_target_id);
      }
      in_ring |= child_in_ring; // Probably indirect edge to a loop merge block.
    }

    blk_stack.resize(depth);
    return in_ring;
  }
  std::set<spv::Id> collect_ring_blks(InstrIdx loop_merge_idx) {
    spv::Id target_label_id =
      ctxt().get_code_block_by_loop_merge_idx(loop_merge_idx).label_id;

    std::set<spv::Id> body_blk_label_ids;
    std::vector<spv::Id> blk_stack_label_ids { target_label_id };

    // Don't register the loop merge block itself.
    collect_ring_blks_impl(body_blk_label_ids, blk_stack_label_ids);
    return body_blk_label_ids;
  }

  virtual void visit() override final {
    OpLoopMerge loop_merge;
    if (!ctxt().try_parse_instr(instr(), loop_merge)) { return; }

    std::set<spv::Id> blks = collect_ring_blks(idx());
    // Ignore the continue block, we don't wanna duplicate instruction in the
    // continue block anyway.
    blks.erase(loop_merge.continue_block);
    
    std::vector<spv::Id> body_blocks;
    for (spv::Id blk : blks) {
      body_blocks.emplace_back(blk);
    }

    std::vector<IterVar> itervars;
    IterVarExtractor itervar_extractor(itervars);

    const CodeBlock& code_block =
      ctxt().get_code_block_by_label_id(loop_merge.continue_block);

    SpirvPass(ctxt())
      .with_visitor(itervar_extractor)
      .apply_ranged(instrs(), code_block.beg, code_block.end);

    Loop loop {};
    loop.merge_block = loop_merge.merge_block;
    loop.continue_block = loop_merge.continue_block;
    loop.body_blocks = std::move(body_blocks);
    loop.loop_ctrl = loop_merge.loop_ctrl;
    loop.itervars = std::move(itervars);
    ctxt().loop_by_loop_merge_idx[idx()] = std::move(loop);
  }
};

struct IdDependencyExtractor : public SpirvVisitor {
  virtual void visit() override final {
    ctxt().dependencies_by_instr_idx.emplace_back(liella::collect_id_refs(instr()));
  }
};

// -----------------------------------------------------------------------------

SpirvBinary process(const SpirvBinary& spv) {
  Context ctxt {};

  ExprExtractor expr_extractor {};
  CodeBlockExtractor block_extractor {};
  IdDependencyExtractor id_dependency_extractor {};

  SpirvPass(ctxt)
    .with_visitor(expr_extractor)
    .with_visitor(block_extractor)
    .with_visitor(id_dependency_extractor)
    .apply(spv.instrs);

  LoopExtractor loop_extractor {};

  SpirvPass(ctxt)
    .with_visitor(loop_extractor)
    .apply(spv.instrs);
  return spv;
}

int main(int argc, const char** argv) {
  using namespace liella;

  if (argc <= 1) {
    std::cout << "input path not specified" << std::endl;
    return -1;
  }
  if (argc <= 2) {
    std::cout << "output path not specified" << std::endl;
    return -1;
  }

  std::vector<uint32_t> spv = load_spv(argv[1]);

  {
    auto spv_bin = deserialize_spv(spv);
    spv_bin = process(spv_bin);
    spv = serialize_spv(spv_bin);
  }

  std::cout << spv.size() << " words" << std::endl;
  store_spv(argv[2], spv);

  std::cout << "success" << std::endl;
  return 0;
}
