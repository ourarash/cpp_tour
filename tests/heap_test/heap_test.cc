#include "src/lib/heap.h"

#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "src/lib/utility.h"  // Necessary for PrintVector

Heap ConvertToHeap(const std::vector<int> &input) {
  Heap result_heap;

  for (int e : input) {
    result_heap.push(e);
  }
  return result_heap;
}

//-----------------------------------------------------------------------------
// Building
//-----------------------------------------------------------------------------
TEST(HeapTest, ConvertToHeap) {
  Heap h;
  std::vector<int> in{50, 11, 22, 3, 44, 35, 16, 7, 18, 19, 10, 4, 2, 13, 1};
  auto actual = h.ConvertToHeap(in);
  std::vector<int> expected{1,  3,  2,  7,  10, 4,  13, 11,
                            18, 19, 44, 50, 35, 22, 16};

  EXPECT_EQ(actual, expected);
}
