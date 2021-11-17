// # Expression Registry
// @PENGUINLIONG
#pragma once
#include <map>
#include "liella/spv-instr.hpp"

namespace liella {

typedef uint32_t InstrIdx;

struct ExprRegistry {
  std::map<uint32_t, InstrIdx> expr_instrs;

  void visit(InstrIdx idx, const Instruction& instr) {
  }
};

struct VariableRegistry {
  struct VariableStore {
    InstrIdx idx;
    spv::Id src;
  };
  std::map<spv::Id, std::vector<VariableStore>> var_stores;

  void visit(uint32_t idx, const Instruction& instr) {
    if (instr.opcode == spv::OpStore) {
      spv::Id var = (spv::Id)instr.operands[0].value;
      spv::Id src = (spv::Id)instr.operands[1].value;

      VariableStore var_store {};
      var_store.idx = idx;
      var_store.src = src;
      var_stores[var].emplace_back(var_store);
    }
  }
};

struct LoopRegistry {
  struct StructuredLoop {
    spv::Id merge_blk;
    spv::Id continue_blk;
    spv::LoopControlMask loop_ctrl;
  };
  std::vector<StructuredLoop> structured_loops;

  void visit(InstrIdx idx, const Instruction& instr) {
    if (instr.opcode == spv::OpLoopMerge) {
      assert(instr.operands.size() == 3);
      StructuredLoop structured_loop {};
      structured_loop.merge_blk = instr.operands[0].value;
      structured_loop.continue_blk = instr.operands[1].value;
      structured_loop.loop_ctrl = (spv::LoopControlMask)instr.operands[2].value;
      structured_loops.emplace_back(structured_loop);
    }
  }
};

struct BlockRegistry {
private:
  spv::Id cur_blk_label_id;
public:
  struct CodeBlock {
    InstrIdx beg;
    InstrIdx end;
  };
  std::map<spv::Id, CodeBlock> blks;

  void visit(uint32_t idx, const Instruction& instr) {
    switch (instr.opcode) {
    case spv::OpLabel:
    {
      assert(cur_blk_label_id == 0);
      assert(instr.operands.size() == 1);
      cur_blk_label_id = instr.operands[0].value;
      blks[cur_blk_label_id].beg = idx;
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
      blks[cur_blk_label_id].end = idx;
      cur_blk_label_id = 0;
      break;
    }
    default: break;
    }
  }
};

} // namespace liella
