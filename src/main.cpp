// # Liella Program Entrance
// @PENGUINLIONG
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "liella/spv-instr.hpp"
#include "liella/collect-id-refs.hpp"
#include "liella/hash-instr.hpp"
#include "liella/op2name.hpp"

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

// To get an `InstrHash`, feed the hasher with literal operands and zero-feed
// with zero if the operand is an ID reference, in specification order.
// instruction.
typedef uint64_t InstrHash;
// Feed the hasher first with an `InstrHash` and then the `InstrHash`es of all
// directly ID-referenced instructions we skipped before.
typedef uint64_t DerefInstrHash;
// Feed the hasher with `InstrHash` and then `InstrHash`es of all directly or
// indirectly ID referenced instructions.
typedef uint64_t FullChainHash;

struct CodeBlock {
  spv::Id label_id;
  InstrIdx beg;
  InstrIdx end;
  std::vector<spv::Id> branch_target_ids;
};
struct IterVar {
  spv::Id id;
  uint32_t stride;
};
struct Loop {
  spv::Id merge_block;
  spv::Id continue_block;
  std::vector<spv::Id> body_blocks;
  spv::LoopControlMask loop_ctrl;
  std::vector<spv::Id> itervar_ids;
};
struct InstrAttribute {
  std::set<spv::Id> itervar_ids;
  InstrHash hash;
  DerefInstrHash deref_hash;
};
//           (+ _ _)
//               \
//          (+ 1 (* _ _))
//               / \
//  (+ 1 (* 2 3))   (+ 1 (* 4 5))
struct InstrHashTree;
struct InstrHashTreeVariant {
  bool is_itervar_constexpr;
  std::vector<InstrIdx> instrs;
  std::vector<InstrHashTree> operand_trees;
};
struct InstrHashTree {
  spv::Op op;
  std::map<InstrHash, InstrHashTreeVariant> variants;
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
  std::vector<bool> has_results;
  std::map<spv::Id, InstrIdx> instr_idx_by_result_id;
  InstrIdx get_instr_idx_by_id(spv::Id id) const {
    return instr_idx_by_result_id.at(id);
  }
  const Instruction& get_instr_by_id(spv::Id id) const {
    return get_instr_by_idx(get_instr_idx_by_id(id));
  }
  template<typename TOp>
  bool try_parse_instr_by_id(spv::Id id, TOp& out) {
    return try_parse_instr(get_instr_by_id(id), out);
  }
  bool is_instr_stmt(InstrIdx idx) const {
    return has_results.at(idx) == false;
  }
  bool is_instr_expr(InstrIdx idx) const {
    return has_results.at(idx) == true;
  }

  // Provided by `CodeBlockExtractor`.
  std::map<spv::Id, CodeBlock> code_block_by_label_id;
  std::map<InstrIdx, spv::Id> label_id_by_loop_merge_idx;
  const CodeBlock& get_code_block_by_label_id(spv::Id id) const {
    return code_block_by_label_id.at(id);
  }
  const CodeBlock& get_code_block_by_loop_merge_idx(
    InstrIdx loop_merge_idx
  ) const {
    spv::Id label_id = label_id_by_loop_merge_idx.at(loop_merge_idx);
    return get_code_block_by_label_id(label_id);
  }

  // Provided by `IdDependencyExtractor`.
  std::vector<std::vector<spv::Id>> dependencies_by_instr_idx;
  const std::vector<spv::Id>& get_instr_dependencies_by_idx(InstrIdx idx) {
    return dependencies_by_instr_idx[idx];
  }
  const std::vector<spv::Id>& get_instr_dependencies_by_id(spv::Id id) {
    return get_instr_dependencies_by_idx(get_instr_idx_by_id(id));
  }

  // Provided by `LoopExtractor`.
  std::map<spv::Id, Loop> loop_by_loop_merge_idx;
  std::map<spv::Id, IterVar> itervar_by_idx;
  const Loop& get_loop_by_idx(InstrIdx idx) const {
    return loop_by_loop_merge_idx.at(idx);
  }
  bool is_idx_itervar(InstrIdx idx) const {
    return itervar_by_idx.find(idx) != itervar_by_idx.end();
  }
  bool is_id_itervar(spv::Id id) const {
    return is_idx_itervar(get_instr_idx_by_id(id));
  }

  // Provided by `InstrAttributeExtractor`.
  std::vector<InstrAttribute> instr_attribute_by_idx;
  bool is_instr_attribute_available_for_idx(InstrIdx idx) const {
    return idx < instr_attribute_by_idx.size();
  }
  const InstrAttribute& get_instr_attribute_by_idx(InstrIdx idx) const {
    return instr_attribute_by_idx.at(idx);
  }
  const std::set<spv::Id>& get_instr_loop_dependencies(InstrIdx idx) const {
    return get_instr_attribute_by_idx(idx).itervar_ids;
  }
  InstrHash get_instr_hash_by_idx(InstrIdx idx) const {
    return get_instr_attribute_by_idx(idx).hash;
  }
  InstrHash get_instr_hash_by_id(spv::Id id) const {
    return get_instr_attribute_by_idx(get_instr_idx_by_id(id)).hash;
  }
  InstrHash get_deref_instr_hash_by_idx(InstrIdx idx) const {
    return get_instr_attribute_by_idx(idx).deref_hash;
  }
  InstrHash get_deref_instr_hash_by_id(spv::Id id) const {
    return get_instr_attribute_by_idx(get_instr_idx_by_id(id)).deref_hash;
  }

  // Provided by `InstrHashForestBuilder`.
  std::map<InstrHash, InstrHashTree> instr_hash_forest;

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
    ctxt().has_results.emplace_back(has_result);
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

struct IdDependencyExtractor : public SpirvVisitor {
  virtual void visit() override final {
    std::vector<uint32_t> id_refs = liella::collect_id_refs(instr());
    ctxt().dependencies_by_instr_idx.emplace_back(id_refs);
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
    out.memory_operand =
      it.ate() ? spv::MemoryAccessMaskNone : (spv::MemoryAccessMask)it.u32();
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
    out.memory_operand =
      it.ate() ? spv::MemoryAccessMaskNone : (spv::MemoryAccessMask)it.u32();
    return out;
  }
};

// Apply this only to instruction in continue blocks.
struct IterVarExtractor : public SpirvVisitor {
  std::vector<spv::Id>* itervar_ids;
  IterVarExtractor(std::vector<spv::Id>& itervar_ids) :
    itervar_ids(&itervar_ids) {}

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
    out.id = store.pointer;
    out.stride = stride;
    auto idx = ctxt().get_instr_idx_by_id(store.pointer);
    ctxt().itervar_by_idx[idx] = std::move(out);
    itervar_ids->emplace_back(store.pointer);
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

    std::vector<spv::Id> itervar_ids;
    IterVarExtractor itervar_extractor(itervar_ids);

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
    loop.itervar_ids = std::move(itervar_ids);
    ctxt().loop_by_loop_merge_idx[idx()] = std::move(loop);
  }
};

struct InstrAttributeExtractor : public SpirvVisitor {
  virtual void visit() override final {
    std::set<spv::Id> itervar_ids;

    const auto& ref_ids = ctxt().get_instr_dependencies_by_idx(idx());

    for (auto ref_id : ref_ids) {
      if (ctxt().is_id_itervar(ref_id)) {
        itervar_ids.emplace(ref_id);
      } else {
        auto idx = ctxt().get_instr_idx_by_id(ref_id);
        // It's possible to have a forward reference that `idx` is beyond the
        // current instruction index, so even though such reference might refer
        // to iteration variables, we only have an empty cache in
        // `ctxt().instr_loop_dependencies` at the moment.
        //
        // In most cases such forward reference is used for attribution and
        // debug info, so we can safely ignore them. Just be aware of this.
        if (ctxt().is_instr_attribute_available_for_idx(idx)) {
          const auto& cached_itervar_ids =
            ctxt().get_instr_loop_dependencies(idx);
          for (spv::Id itervar_id : cached_itervar_ids) {
            itervar_ids.emplace(itervar_id);
          }
        }
      }
    }

    InstrHash instr_hash;
    {
      Fnv hasher {};
      liella::hash_instr(hasher, instr());
      instr_hash = hasher.hash;
    }
    DerefInstrHash deref_instr_hash;
    {
      Fnv hasher {};
      hasher.feed(instr_hash);
      for (spv::Id dep_id : ctxt().get_instr_dependencies_by_idx(idx())) {
        auto idx = ctxt().get_instr_idx_by_id(dep_id);
        // Still we ignore forward references here.
        if (idx < this->idx()) {
          hasher.feed(ctxt().get_instr_hash_by_idx(idx));
        } else {
          hasher.feed(0);
        }
      }
      deref_instr_hash = hasher.hash;
    }


    InstrAttribute out {};
    out.itervar_ids = std::move(itervar_ids);
    out.hash = instr_hash;
    out.deref_hash = deref_instr_hash;
    ctxt().instr_attribute_by_idx.emplace_back(std::move(out));
  }
};

// -----------------------------------------------------------------------------

struct InstrHashForestBuilder : public SpirvVisitor {
  InstrHashTreeVariant build_variant(InstrIdx idx) {
    const Instruction& instr = ctxt().get_instr_by_idx(idx);
    auto dep_ids = ctxt().get_instr_dependencies_by_idx(idx);

    std::vector<InstrHashTree> operand_trees;
    for (size_t i = 0; i < dep_ids.size(); ++i) {
      InstrIdx dep_idx = ctxt().get_instr_idx_by_id(dep_ids.at(i));
      operand_trees.emplace_back(build_tree(dep_idx));
    }

    InstrHashTreeVariant variant {};
    variant.is_itervar_constexpr = false; // FIXME: (penguinliong)
    variant.operand_trees = std::move(operand_trees);
    // `variant.instrs` is marked later.
    return variant;
  }
  InstrHashTree build_tree(InstrIdx idx) {
    const Instruction& instr = ctxt().get_instr_by_idx(idx);
    auto instr_hash = ctxt().get_instr_hash_by_idx(idx);

    InstrHashTree out {};
    // `out.variants` will be marked later.
    out.op = instr.opcode;
    return out;
  }
  void mark_tree(InstrHashTree& tree, InstrIdx idx) {
    const Instruction& instr = ctxt().get_instr_by_idx(idx);
    auto instr_hash = ctxt().get_instr_hash_by_idx(idx);

    // If the variant has not been registered before, register it first.
    if (tree.variants.find(instr_hash) == tree.variants.end()) {
      tree.variants[instr_hash] = build_variant(idx);
    }

    // Mark that the current variant of the tree node is used by this current
    // instruction.
    InstrHashTreeVariant& variant = tree.variants[instr_hash];
    variant.instrs.emplace_back(idx);

    // Further mark the variants of subtrees.
    const auto& dep_ids = ctxt().get_instr_dependencies_by_idx(idx);
    for (size_t i = 0; i < dep_ids.size(); ++i) {
      spv::Id dep_id = dep_ids[i];
      auto& operand_tree = variant.operand_trees[i];
      mark_tree(operand_tree, ctxt().get_instr_idx_by_id(dep_id));
    }
  }
  virtual void visit() override final {
    auto instr_hash = ctxt().get_instr_hash_by_idx(idx());
    auto it = ctxt().instr_hash_forest.find(instr_hash);
    if (it == ctxt().instr_hash_forest.end()) {
      auto pair = std::make_pair(instr_hash, build_tree(idx()));
      ctxt().instr_hash_forest.emplace_hint(it, std::move(pair));
    }
    mark_tree(ctxt().instr_hash_forest[instr_hash], idx());
  }
};

// TODO: (penguinliong)
// 1. Identify implicit loops and merge them as one itervar-controlled
//    instruction bundle.
// 2. Identify ranged structured loops and merge the instructions within as one
//    or more itervar-controlled instruction bundle.

// Implicit loops are sequential statements differs to each other only by a
// constant or a itervar-constexpr operand.
struct ImplicitLoopFinder : public SpirvVisitor {
  struct DiffPoint {
    uint32_t ref_pos;
    InstrIdx ia;
    InstrIdx ib;
  };
  void stmt_diff_impl(
    InstrIdx ia,
    InstrIdx ib,
    std::vector<DiffPoint>& diff_pts,
    uint32_t& ref_pos_counter
  ) {
    uint32_t ref_pos = ref_pos_counter++;
    InstrHash a_hash = ctxt().get_instr_hash_by_idx(ia);
    InstrHash b_hash = ctxt().get_instr_hash_by_idx(ib);
    if (a_hash != b_hash) {
      DiffPoint diff_pt {};
      diff_pt.ref_pos = ref_pos;
      diff_pt.ia = ia;
      diff_pt.ib = ib;
      diff_pts.emplace_back(diff_pt);
    } else {
      const auto& a_deps = ctxt().get_instr_dependencies_by_idx(ia);
      const auto& b_deps = ctxt().get_instr_dependencies_by_idx(ib);
      assert(a_deps.size() == b_deps.size());
      for (size_t i = 0; i < a_deps.size(); ++i) {
        auto a_dep_idx = ctxt().get_instr_idx_by_id(a_deps[i]);
        auto b_dep_idx = ctxt().get_instr_idx_by_id(b_deps[i]);
        stmt_diff_impl(a_dep_idx, b_dep_idx, diff_pts, ref_pos_counter);
      }
    }
  }
  std::vector<DiffPoint> stmt_diff(InstrIdx ia, InstrIdx ib) {
    uint32_t ref_pos_counter = 0;
    std::vector<DiffPoint> diff_pts {};
    stmt_diff_impl(ia, ib, diff_pts, ref_pos_counter);
    return diff_pts;
  }

  struct ImplicitLoop {
    InstrIdx beg = 0;
    InstrIdx end = 0;
    int64_t stride = -1;

    constexpr uint32_t nunroll() const {
      return (end - beg);
    }
  };
  std::vector<ImplicitLoop> implicit_loops;
  virtual void visit() override final {
    if (implicit_loops.empty()) {
      implicit_loops.emplace_back();
      return;
    }

    ImplicitLoop& implicit_loop = implicit_loops.back();

    bool is_similar = true;
    int64_t expected_stride = -1;
    auto diff_pts = stmt_diff(implicit_loop.beg, idx());
    for (auto diff_pt : diff_pts) {
      const Instruction& a = ctxt().get_instr_by_idx(diff_pt.ia);
      const Instruction& b = ctxt().get_instr_by_idx(diff_pt.ib);

      if (a.is(spv::OpConstant) && b.is(spv::OpConstant)) {
        auto a_op = OpConstant::parse(a.iter());
        auto b_op = OpConstant::parse(b.iter());
        int64_t stride = std::abs(a_op.literal - b_op.literal);

        if (expected_stride < 0) {
          expected_stride = stride;
        } else {
          is_similar &= expected_stride == stride;
        }

        auto a_ty_deref_hash =
          ctxt().get_deref_instr_hash_by_id(a_op.result_ty_id);
        auto b_ty_deref_hash =
          ctxt().get_deref_instr_hash_by_id(b_op.result_ty_id);
        is_similar &= a_ty_deref_hash == b_ty_deref_hash;
      } else {
        is_similar = false;
        break;
      }
    }

    if (implicit_loop.stride < 0) {
      // It's possible this `stride` assigned with `-1` when the instructions
      // are exactly the same. It's common when multiple variables of the same
      // type being allocated.
      implicit_loop.stride = expected_stride;
    } else {
      int64_t long_stride = implicit_loop.stride * implicit_loop.nunroll();
      is_similar &= long_stride == expected_stride;
    }

    if (is_similar) {
      implicit_loop.end = idx() + 1;
    } else {
      if (implicit_loop.beg == idx() - 1) {
        // Reuse the last structure if the current instruction pair doesn't form
        // an implicit loop.
        implicit_loop.beg = idx();
        implicit_loop.end = 0;
      } else {
        // Otherwise, close the implicit loop because there is no other similar
        // statements following.
        implicit_loops.emplace_back();
        implicit_loops.back().beg = idx();
      }
    }
  }
};

// -----------------------------------------------------------------------------

void dbg_print_instr_hash_tree_impl(
  const InstrHashTree& tree,
  std::stringstream& ss
) {
  bool first = true;
  for (const auto& variant : tree.variants) {
    if (first) {
      first = false;
    } else {
      ss << ":";
    }
    ss << "(" << op2name(tree.op);
    for (const auto& operand_tree : variant.second.operand_trees) {
      ss << " ";
      dbg_print_instr_hash_tree_impl(operand_tree, ss);
    }
    ss << ")";
  }
}
std::string dbg_print_instr_hash_tree(const Context& ctxt) {
  std::stringstream ss;
  for (const auto& pair : ctxt.instr_hash_forest) {
    dbg_print_instr_hash_tree_impl(pair.second, ss);
    ss << std::endl;
  }
  return ss.str();
}

// A ramped statement is a sequence of statements to apply a same operation
// to multiple data, in which the only different between the statements is their
// indices which are itervar-constant-expressions.
struct RampedStmt {
  std::vector<InstrIdx> instrs;
};

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

  InstrAttributeExtractor instr_loop_dependency_extractor {};

  SpirvPass(ctxt)
    .with_visitor(instr_loop_dependency_extractor)
    .apply(spv.instrs);

  InstrHashForestBuilder instr_hash_forest_builder;

  SpirvPass(ctxt)
    .with_visitor(instr_hash_forest_builder)
    .apply(spv.instrs);

  std::cout << dbg_print_instr_hash_tree(ctxt);

  ImplicitLoopFinder implicit_loop_finder;

  SpirvPass(ctxt).with_visitor(implicit_loop_finder)
    .apply(spv.instrs);

  if (implicit_loop_finder.implicit_loops.back().end == 0) {
    implicit_loop_finder.implicit_loops
      .erase(implicit_loop_finder.implicit_loops.end() - 1);
  }

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
