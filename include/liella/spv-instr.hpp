// # SPIR-V Instruction Utilities
// @PENGUINLIONG
#include <cstdint>
#include <vector>
#include "spirv/unified1/SPIRV.hpp"

namespace liella {

enum OperandType {
  OPERAND_TYPE_LITERAL,
  OPERAND_TYPE_WEAK_REF,
  OPERAND_TYPE_STRONG_REF,
};
struct Operand {
  OperandType operand_ty;
  uint32_t value;
};
struct Instruction {
  uint32_t opcode;
  std::vector<Operand> operands;
};

struct SpirvBinary {
  uint32_t magic;
  uint32_t version;
  uint32_t generator_magic;
  uint32_t bound;
  uint32_t reserved;
  std::vector<Instruction> instrs;
};

SpirvBinary deserialize_spv(const std::vector<uint32_t>& spv) {
  SpirvBinary out {};
  assert(spv.size() > 5);
  out.magic = spv[0];
  out.version = spv[1];
  out.generator_magic = spv[2];
  out.bound = spv[3];
  out.reserved = spv[4];
  assert(out.magic == spv::MagicNumber);

  auto beg = spv.begin() + 5;
  auto end = spv.end();
  while (beg != end) {
    uint32_t instr_size = *beg >> 16;
    uint32_t opcode = *beg & 0xFFFF;
    auto next_beg = beg + instr_size;

    Instruction instr {};
    instr.opcode = opcode;
    for (auto pos = beg + 1; pos < next_beg; ++pos) {
      Operand operand {};
      operand.operand_ty = OPERAND_TYPE_LITERAL;
      operand.value = *pos;
      instr.operands.emplace_back(std::move(operand));
    }
    beg = next_beg;
    out.instrs.emplace_back(instr);
  }

  return out;
}

std::vector<uint32_t> serialize_spv(const SpirvBinary& spv) {
  std::vector<uint32_t> out;
  out.emplace_back(spv.magic);
  out.emplace_back(spv.version);
  out.emplace_back(spv.generator_magic);
  out.emplace_back(spv.bound);
  out.emplace_back(spv.reserved);

  for (const auto& instr : spv.instrs) {
    uint32_t instr_size = instr.operands.size() + 1;
    uint32_t instr_header = (instr.opcode & 0xFFFF) + (instr_size << 16);
    out.emplace_back(instr_header);
    for (const auto& operand : instr.operands) {
      out.emplace_back(operand.value);
    }
  }

  return out;
}

} // namespace tinyspv
