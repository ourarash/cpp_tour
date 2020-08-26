#include "src/lib/solution.h"

#include <vector>

#include "gtest/gtest.h"

TEST(HelloWorldShould, ReturnHelloWorld) {
  Solution solution;
  std::string actual = solution.PrintHelloWorld();
  std::string expected = "**** Hello World ****";
  EXPECT_EQ(expected, actual);
}

TEST(FindMax, ShouldWorkForSimpleVector) {
  Solution solution;

  std::vector<int> inputs = {1, 2, 3, 4, 5};
  int max = solution.FindMax(inputs);

  EXPECT_EQ(max, 5);
}

TEST(FindMax, ShouldWorkForEmptyVector) {
  Solution solution;

  std::vector<int> inputs = {};
  int max = solution.FindMax(inputs);

  EXPECT_EQ(max, -1);
}

TEST(FindMax, ShouldWorkForVectorOfAllEqualNumber) {
  Solution solution;

  std::vector<int> inputs = {1, 1, 1, 1};
  int max = solution.FindMax(inputs);

  EXPECT_EQ(max, 1);
}