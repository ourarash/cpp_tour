#include "src/lib/backtracking/backtracking.h"

#include <vector>

#include "gtest/gtest.h"

TEST(BacktrackingTest, Permute) {
  std::vector<int> in{1, 2, 3};
  std::vector<std::vector<int>> expected{{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                         {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
  auto actual = Backtracking::Permute(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, EightQueen_4) {
  auto solutions = Backtracking::SolveNQueen(4);
  EXPECT_EQ(solutions.size(), 2);
}

TEST(BacktrackingTest, EightQueen_8) {
  auto solutions = Backtracking::SolveNQueen(8);
  EXPECT_EQ(solutions.size(), 92);
}
