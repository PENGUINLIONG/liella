// # Liella Program Entrance
// @PENGUINLIONG
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "liella/spv-instr.hpp"

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

struct IterVar {
  spv::Id var_id;
  uint32_t stride;
};
struct StructuredLoop {
  InstrIdx loop_merge_instr;
  std::vector<IterVar> iter_vars;
};
struct StructuredLoopRegistry {
  std::map<InstrIdx, StructuredLoop> structure_loops;

  void find_loop_merge_instr(InstrIdx i, const std::vector<Instruction>& instrs) {
    const Instruction& instr = instrs[i];
    if (instr.opcode != spv::OpLoopMerge) { return; }

    auto operands = instr.iter();
    spv::Id merge_block = operands.id();
    spv::Id continue_block = operands.id();

    
  }

  void process(const std::vector<Instruction>& instrs) {
    for (uint32_t i = 0; i < instrs.size(); ++i) {

    }
  }
};



struct CodeBlock {
  InstrIdx beg;
  InstrIdx end;
};
struct SpirvConsumer {
private:
  const Instruction* instrs;
  size_t ninstr;
  std::map<spv::Id, InstrIdx> idx_by_ref;
  std::map<spv::Id, CodeBlock> block_by_label_id;

  static inline std::map<spv::Id, InstrIdx> collect_refs(
    const Instruction* instrs,
    size_t ninstr
  ) {
    std::map<spv::Id, InstrIdx> out {};
    for (size_t i = 0; i < ninstr; ++i) {
      const Instruction& instr = instrs[i];
      bool has_result = false;
      bool has_result_ty = false;
      spv::HasResultAndType(instr.opcode, &has_result, &has_result_ty);
      if (has_result) {
        auto operands = instr.iter();
        if (has_result_ty) {
          assert(instr.operands.size() >= 2);
          spv::Id result_ty_id = operands.id();
          spv::Id result_id = operands.id();
          out[result_id] = i;
        } else {
          assert(instr.operands.size() >= 1);
          spv::Id result_id = operands.id();
          out[result_id] = i;
        }
      }
    }
    return out;
  }
  static inline std::map<spv::Id, CodeBlock> collect_blocks(
    const Instruction* instrs,
    size_t ninstr
  ) {
    std::map<spv::Id, CodeBlock> out {};
    uint32_t cur_blk_label_id;
    for (size_t i = 0; i < ninstr; ++i) {
      const Instruction& instr = instr;
      switch (instr.opcode) {
      case spv::OpLabel:
      {
        assert(cur_blk_label_id == 0);
        assert(instr.operands.size() == 1);
        cur_blk_label_id = instr.iter().id();
        out[cur_blk_label_id].beg = i;
        break;
      }
      case spv::OpBranch:
      case spv::OpBranchConditional:
      case spv::OpSwitch:
      case spv::OpReturn:
      case spv::OpReturnValue:
      case spv::OpKill:
      case spv::OpUnreachable:
      {
        assert(cur_blk_label_id != 0);
        out[cur_blk_label_id].end = i;
        cur_blk_label_id = 0;
        break;
      }
      default: break;
      }
    }
    return out;
  }

protected:
  SpirvConsumer(const Instruction* instrs, size_t ninstr) :
    instrs(instrs),
    ninstr(ninstr),
    idx_by_ref(collect_refs(instrs, ninstr)),
    block_by_label_id(collect_blocks(instrs, ninstr)) {}
  SpirvConsumer(const std::vector<Instruction>& instrs) :
    SpirvConsumer(instrs.data(), instrs.size()) {}

  const Instruction& get_instr_by_idx(InstrIdx idx) const {
    return instrs[idx];
  }
  const Instruction& get_instr_by_ref(spv::Id ref) const {
    return get_instr_by_idx(idx_by_ref[ref]);
  }
  const CodeBlock& get_block_by_label_id(spv::Id ref) const {
    return block_by_label_id[ref];
  }

  // These are set during execution of `process`.
  InstrIdx idx;
  const Instruction* instr;

public:
  inline void process() {
    for (size_t i = 0; i < ninstr; ++i) {
      idx = i;
      instr = &instrs[i];
      visit();
    }
  }
  virtual void visit() = 0;
};





struct IterVar {
  spv::Id var_id;
  uint32_t stride;
};
struct IterVarExtractor : public SpirvConsumer {
  std::vector<IterVar> find_itervar() {

  }
  void visit() {
    std::vector<IterVar> out;
    if (instr->opcode == spv::OpStore) {
      find_itervar();
    }
  }

};
struct LoopExtractor : public SpirvConsumer {
  std::vector<IterVar> find_itervar() {
    std::vector<IterVar> itervars;
    for ()
  }
  virtual void visit() override {
    if (instr->opcode == spv::OpLoopMerge) {
      auto operands = instr->iter();
      const auto& continue_block = get_block_by_label_id(operands.id());
      const auto& merge_block = operands.id();
      
    }
  }
};




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

    for (size_t i = 0; i < spv_bin.instrs.size(); ++i) {
      const auto& instr = *spv_bin.instrs[i];
    }

    spv = serialize_spv(spv_bin);
  }

  std::cout << spv.size() << " words" << std::endl;
  store_spv(argv[2], spv);

  std::cout << "success" << std::endl;
  return 0;
}
