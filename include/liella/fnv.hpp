// # FNV-1a Hasher
// @PENGUINLIONG
// https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function
#include <cstdint>

namespace liella {

struct Fnv {
  static constexpr uint64_t FVN_OFFSET_BIAS = 0xcbf29ce484222325;
  static constexpr uint64_t FVN_PRIME = 0x100000001b3;
  uint64_t hash = FVN_OFFSET_BIAS;
  inline void feed(const void* data, size_t size) {
    for (size_t i = 0; i < size; ++i) {
      hash = hash ^ (uint64_t)*(const uint8_t*)data;
      hash = hash * FVN_PRIME;
    }
  }
  template<typename T>
  inline void feed(const T& data) {
    feed(&data, sizeof(T));
  }
};

} // namespace liella
