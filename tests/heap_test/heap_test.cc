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

TEST(HeapTest, PopWorksCorrectly) {
  Heap h;
  std::vector<int> in{50, 11, 22, 3, 44, 35, 16, 7, 18, 19, 10, 4, 2, 13, 1};
  auto in_copy = in;
  h.ConvertToHeap(in);

  std::sort(in_copy.begin(), in_copy.end());
  for (auto e : in_copy) {
    EXPECT_EQ(h.top(), e);
    h.pop();
  }
  EXPECT_EQ(h.top(), INT_MAX);
  EXPECT_TRUE(h.empty());
}

TEST(HeapTest, PushWorksCorrectly) {
  Heap h;
  std::vector<int> in{50, 11, 22, 3, 44, 35, 16, 7, 18, 19, 10, 4, 2, 13, 1};

  for (int i = 0; i < in.size(); i++) {
    auto e = in[i];
    h.push(e);
    EXPECT_EQ(h.top(), *(std::min_element(in.begin(), in.begin() + i + 1)));
  }
}

TEST(HeapSortTest, WorksCorrectly) {
  Heap h;
  std::vector<int> in{50, 11, 22, 3, 44, 35, 16, 7, 18, 19, 10, 4, 2, 13, 1};

  auto actual  = HeapSort(in);
  std::sort(in.begin(), in.end());
  EXPECT_EQ(actual, in);
}
