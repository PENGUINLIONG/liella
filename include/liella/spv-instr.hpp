// # SPIR-V Instruction Utilities
// @PENGUINLIONG
#pragma once
#include <cassert>
#include <cstdint>
#include <vector>
#include <memory>
#define SPV_ENABLE_UTILITY_CODE
#include "spirv/unified1/SPIRV.hpp"
#include "liella/fnv.hpp"

namespace liella {

typedef uint32_t InstrIdx;

struct OperandIterator {
  const uint32_t* pos;
  const uint32_t* end;

  inline uint32_t u32() { return *(pos++); }
  inline spv::Id id() { return (spv::Id)*(pos++); }
  inline const char* str() {
    const char* out = (const char*)pos;
    do {
      if ((*(pos++) >> 24) == 0) {
        break;
      }
    } while (!ate());
    return out;
  }
  // Returns false if the string is ended by this 32b word.
  inline bool str_u32(uint32_t& out) {
    out = *(pos++);
    return (out >> 24) != 0;
  }

  inline bool ate() const { return pos == end; }
};
struct Instruction {
  spv::Op opcode;
  std::vector<uint32_t> operands;

  inline OperandIterator iter() const {
    return OperandIterator {
      operands.data(),
      operands.data() + operands.size()
    };
  }
  inline bool is(spv::Op op) const { return opcode == op; }
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
    instr.opcode = (spv::Op)opcode;
    for (auto pos = beg + 1; pos < next_beg; ++pos) {
      instr.operands.emplace_back(*pos);
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
      out.emplace_back(operand);
    }
  }

  return out;
}


// Out internal structure.
struct Instr;
struct Operand {
  uint32_t literal;
  std::shared_ptr<Instr> ref;

  inline bool is_literal() const { return ref == nullptr; }
  inline bool is_ref() const { return ref != nullptr; }
};
inline Operand make_operand(uint32_t literal) {
  return { literal, nullptr };
}
inline Operand make_operand(const std::shared_ptr<Instr>& ref) {
  return { 0, ref };
}

struct Instr {
  spv::Op op;
  std::vector<Operand> operands;

  inline uint64_t hash(bool deref = false) const {
    Fnv hasher {};
    hasher.feed(op);
    for (const auto& operand : operands) {
      if (operand.is_literal()) {
        hasher.feed(operand.literal);
      } else if (deref) {
        hasher.feed(operand.ref->hash());
      }
    }
    return hasher.hash;
  }
};

struct InstrBuilder {
  Instr inner;

  InstrBuilder(spv::Op op) : inner { op, {} } {}

  void push(uint32_t literal) {
    inner.operands.emplace_back(make_operand(literal));
  }
  void push(const std::shared_ptr<Instr>& ref) {
    inner.operands.emplace_back(make_operand(ref));
  }
  std::shared_ptr<Instr> build() {
    return std::make_shared<Instr>(std::move(inner));
  }
};

} // namespace liella
