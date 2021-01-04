#include "src/lib/dynamic_programming/dynamic_programming.h"

#include <vector>

#include "gtest/gtest.h"

// TEST(DynamicProgrammingTest, MinimumJumps1) {
//   std::vector<int> in{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
//   int expected = 3;
//   auto actual = DynamicProgramming::MinimumJumps(in, in.size() - 1);

//   EXPECT_EQ(actual, expected);
// }

// TEST(DynamicProgrammingTest, MinimumJumps2) {
//   std::vector<int> in{1, 1, 1, 1, 1, 1};
//   int expected = 5;
//   auto actual = DynamicProgramming::MinimumJumps(in, in.size() - 1);

//   EXPECT_EQ(actual, expected);
// }

// TEST(DynamicProgrammingTest, MinimumJumps3) {
//   std::vector<int> in{1, 3, 6, 1, 0, 9};
//   int expected = 3;
//   auto actual = DynamicProgramming::MinimumJumps(in, in.size() - 1);

//   EXPECT_EQ(actual, expected);
// }

// TEST(DynamicProgrammingTest, MinimumJumps4) {
//   std::vector<int> in{1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
//   int expected = 4;
//   auto actual = DynamicProgramming::MinimumJumps(in, in.size() - 1);

//   EXPECT_EQ(actual, expected);
// }

// TEST(DynamicProgrammingTest, MinimumJumps5) {
//   std::vector<int> in(100000, 1);
//   int expected = in.size() - 1;
//   auto actual = DynamicProgramming::MinimumJumps(in, in.size() - 1);

//   EXPECT_EQ(actual, expected);
// }

// TEST(DynamicProgrammingTest, MinimumJumpsMemo5) {
//   std::vector<int> in(100000, 1);
//   int expected = in.size() - 1;
//   auto actual = DynamicProgramming::MinimumJumpsMemo(in, in.size() - 1);

//   EXPECT_EQ(actual, expected);
// }

TEST(DynamicProgrammingTest, NumberOfCombinationSums) {
  std::vector<int> in = {1, 5, 10};

  auto actual = DynamicProgramming::NumberOfCombinationSums(in, 2);
  int expected = 1;
  EXPECT_EQ(actual, expected);

  actual = DynamicProgramming::NumberOfCombinationSums(in, 10);
  expected = 4;
  EXPECT_EQ(actual, expected);

  actual = DynamicProgramming::NumberOfCombinationSums(in, 15);
  expected = 6;
  EXPECT_EQ(actual, expected);

  actual = DynamicProgramming::NumberOfCombinationSums(in, 0);
  expected = 0;
  EXPECT_EQ(actual, expected);
}