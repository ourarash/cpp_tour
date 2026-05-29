#ifndef MULTI_THREADING_RANGE_SUM_H
#define MULTI_THREADING_RANGE_SUM_H

#include <cstdint>

// Adds the integers in [low, high) into *out. Used by the demos that show
// std::thread with std::ref so each thread writes into its own slot of a
// partial-sums vector.
inline void AccumulateRange(uint64_t &out, uint64_t low, uint64_t high) {
  uint64_t sum = 0;
  for (uint64_t i = low; i < high; i++) sum += i;
  out = sum;
}

// Returns the sum of integers in [low, high). Used by the std::async and
// constructor-by-reference demos.
inline uint64_t GetRangeSum(uint64_t low, uint64_t high) {
  uint64_t sum = 0;
  for (uint64_t i = low; i < high; i++) sum += i;
  return sum;
}

#endif
