#include "src/lib/vector_union.h"
#include "gtest/gtest.h"
#include <vector>

TEST(VectorUnion, ShouldHandleEmptySetA) {
  VectorUnionSolution s;
  std::vector<int> a = {}, b = {1, 2, 3, 4};
  std::vector<int> actual = s.Calculate(a, b);
  std::vector<int> expected = b;
  EXPECT_EQ(expected, actual);
}

TEST(VectorUnion, ShouldHandleEmptySetAB) {
  VectorUnionSolution s;
  std::vector<int> a = {}, b = {};
  std::vector<int> actual = s.Calculate(a, b);
  std::vector<int> expected = b;
  EXPECT_EQ(expected, actual);
}


TEST(VectorUnion, ShouldHandleUnion) {
  VectorUnionSolution s;
  std::vector<int> a = {1, 2, 3}, b = {3, 54, 6};
  std::vector<int> actual = s.Calculate(a, b);
  std::vector<int> expected = {1, 2, 3, 6, 54};
  EXPECT_EQ(expected, actual);
}