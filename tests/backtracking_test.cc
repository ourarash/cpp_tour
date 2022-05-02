#include "src/lib/backtracking/backtracking.h"

#include <algorithm>
#include <vector>

#include "gtest/gtest.h"
TEST(BacktrackingTest, Subsets_T1) {
  std::cout << "1" << std::endl;
  std::vector<int> in{0, 1, 2};
  std::vector<std::vector<int>> expected{{},  {2},    {1},    {1, 2},
                                         {0}, {0, 2}, {0, 1}, {0, 1, 2}};
  auto actual = Backtracking::Subsets(in);

  EXPECT_EQ(actual, expected);
}
TEST(BacktrackingTest, Subsets_T2) {
  std::cout << "2" << std::endl;

  std::vector<int> in{0, 1};
  std::vector<std::vector<int>> expected{{}, {1}, {0}, {0, 1}};
  auto actual = Backtracking::Subsets(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, Subsets_2ndSol_T1) {
  std::cout << "3" << std::endl;

  std::vector<int> in{0, 1, 2};
  std::vector<std::vector<int>> expected{{},     {0}, {0, 1}, {0, 1, 2},
                                         {0, 2}, {1}, {1, 2}, {2}};
  auto actual = Backtracking::Subsets_2ndSol(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, Subsets_2ndSol_T2) {
  std::cout << "4" << std::endl;

  std::vector<int> in{0, 1};
  std::vector<std::vector<int>> expected{{}, {0}, {0, 1}, {1}};
  auto actual = Backtracking::Subsets_2ndSol(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, SubsetsWithDup_T1) {
  std::cout << "5" << std::endl;

  std::vector<int> in{1, 2, 2};
  std::vector<std::vector<int>> expected{{},        {1}, {1, 2},
                                         {1, 2, 2}, {2}, {2, 2}};
  auto actual = Backtracking::SubsetsWithDup(in);

  EXPECT_EQ(actual, expected);
}
TEST(BacktrackingTest, SubsetsWithDup_T2) {
  std::cout << "6" << std::endl;

  std::vector<int> in{1, 1, 2, 2};
  std::vector<std::vector<int>> expected{
      {}, {1}, {1, 1}, {1, 1, 2}, {1, 1, 2, 2}, {1, 2}, {1, 2, 2}, {2}, {2, 2}};
  auto actual = Backtracking::SubsetsWithDup(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, Permute) {
  std::cout << "7" << std::endl;

  std::vector<int> in{1, 2, 3};
  std::vector<std::vector<int>> expected{{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                         {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
  auto actual = Backtracking::Permute(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, Permute_recursive) {
  std::vector<int> in{1, 2, 3};
  std::vector<std::vector<int>> expected{{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                         {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
  auto actual = Backtracking::Permute_recursive(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, Permute_recursive_size_4) {
  std::vector<int> in{1, 2, 3, 4};
  std::vector<std::vector<int>> expected{
      {1, 2, 3, 4}, {1, 2, 4, 3}, {1, 3, 2, 4}, {1, 3, 4, 2}, {1, 4, 2, 3},
      {1, 4, 3, 2}, {2, 1, 3, 4}, {2, 1, 4, 3}, {2, 3, 1, 4}, {2, 3, 4, 1},
      {2, 4, 1, 3}, {2, 4, 3, 1}, {3, 1, 2, 4}, {3, 1, 4, 2}, {3, 2, 1, 4},
      {3, 2, 4, 1}, {3, 4, 1, 2}, {3, 4, 2, 1}, {4, 1, 2, 3}, {4, 1, 3, 2},
      {4, 2, 1, 3}, {4, 2, 3, 1}, {4, 3, 1, 2}, {4, 3, 2, 1}};
  auto actual = Backtracking::Permute_recursive(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, PermuteII) {
  std::vector<int> in{1, 1, 3};
  std::vector<std::vector<int>> expected{{1, 1, 3}, {1, 3, 1}, {3, 1, 1}};
  auto actual = Backtracking::PermuteII(in);

  EXPECT_EQ(actual, expected);
}
TEST(BacktrackingTest, PermuteII_2) {
  std::vector<int> in{1, 1, 3, 4};
  std::vector<std::vector<int>> expected{
      {1, 1, 3, 4}, {1, 1, 4, 3}, {1, 3, 1, 4}, {1, 3, 4, 1},
      {1, 4, 1, 3}, {1, 4, 3, 1}, {3, 1, 1, 4}, {3, 1, 4, 1},
      {3, 4, 1, 1}, {4, 1, 1, 3}, {4, 1, 3, 1}, {4, 3, 1, 1}};
  auto actual = Backtracking::PermuteII(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, PermuteII_recursive) {
  std::vector<int> in{1, 1, 3};
  std::set<std::vector<int>> expected{{1, 1, 3}, {1, 3, 1}, {3, 1, 1}};
  auto actual = Backtracking::PermuteII_recursive(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, PermuteII_recursive2) {
  std::vector<int> in{1, 1, 3, 4};
  std::set<std::vector<int>> expected{{1, 1, 3, 4}, {1, 1, 4, 3}, {1, 3, 1, 4},
                                      {1, 3, 4, 1}, {1, 4, 1, 3}, {1, 4, 3, 1},
                                      {3, 1, 1, 4}, {3, 1, 4, 1}, {3, 4, 1, 1},
                                      {4, 1, 1, 3}, {4, 1, 3, 1}, {4, 3, 1, 1}};
  auto actual = Backtracking::PermuteII_recursive(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, PermuteII_recursive_optimized) {
  std::vector<int> in{1, 1, 3};
  std::vector<std::vector<int>> expected{{1, 1, 3}, {1, 3, 1}, {3, 1, 1}};
  auto actual = Backtracking::PermuteII_recursive_optimized(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, PermuteII_recursive_optimized2) {
  std::vector<int> in{1, 1, 3, 4};
  std::vector<std::vector<int>> expected{
      {1, 1, 3, 4}, {1, 1, 4, 3}, {1, 3, 1, 4}, {1, 3, 4, 1},
      {1, 4, 1, 3}, {1, 4, 3, 1}, {3, 1, 1, 4}, {3, 1, 4, 1},
      {3, 4, 1, 1}, {4, 1, 1, 3}, {4, 1, 3, 1}, {4, 3, 1, 1}};
  auto actual = Backtracking::PermuteII_recursive_optimized(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, WordBreak3) {
  std::string s = "aaaaa";
  std::vector<std::string> dic = {"a", "aa", "aaaa"};
  auto actual = Backtracking::WordBreak(s, dic);
  std::vector<std::string> expected = {
      "a a a a a", "a a a aa", "a a aa a", "a aa a a", "a aa aa",
      "a aaaa",    "aa a a a", "aa a aa",  "aa aa a",  "aaaa a"};

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, WordBreak2) {
  std::string s = "aaaa";
  std::vector<std::string> dic = {"a", "aa", "aaa", "aaaa"};
  auto actual = Backtracking::WordBreak(s, dic);
  std::vector<std::string> expected = {"a a a a", "a a aa", "a aa a", "a aaa",
                                       "aa a a",  "aa aa",  "aaa a",  "aaaa"};

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, WordBreak_sol2) {
  std::string s = "aaaa";
  std::vector<std::string> dic = {"a", "aa", "aaa", "aaaa"};
  auto actual = Backtracking::WordBreak_sol2(s, dic);
  std::vector<std::string> expected = {"a a a a", "a a aa", "a aa a", "a aaa",
                                       "aa a a",  "aa aa",  "aaa a",  "aaaa"};

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, WordBreak) {
  std::string s = "catsanddog";
  std::vector<std::string> dic = {"cat", "cats", "and", "sand", "dog"};
  auto actual = Backtracking::WordBreak(s, dic);
  std::vector<std::string> expected = {"cat sand dog", "cats and dog"};

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, WordBreak_T2) {
  std::string s = "amanthisiscorrect";
  std::vector<std::string> dic = {"a",   "aman",    "man",  "this",
                                  "cor", "correct", "rect", "is"};
  auto actual = Backtracking::WordBreak(s, dic);
  std::vector<std::string> expected = {
      "a man this is cor rect", "a man this is correct",
      "aman this is cor rect", "aman this is correct"};

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

TEST(BacktrackingTest, UniquePaths) {
  auto actual = Backtracking::UniquePaths(3, 7);
  EXPECT_EQ(actual, 28);
}

//-----------------------------------------------------------------------------
TEST(TSPWithGasTest, TSP) {
  std::vector<std::vector<int>> weights;
  std::vector<int> gas;

  {
    weights = {
        {0, 40, 20, 35},
        {40, 0, 30, 10},
        {20, 30, 0, 30},
        {35, 10, 30, 0},
    };
    // { 0, 2, 1, 3 }
    gas = {1000, 1000, 1000, 1000};
    EXPECT_EQ(95, Backtracking::TSPWithGas(weights, gas, 0));

    gas = {1, 1, 1, 1};
    EXPECT_EQ(INT_MAX, Backtracking::TSPWithGas(weights, gas, 0));

    gas = {95, 0, 0, 0};
    EXPECT_EQ(95, Backtracking::TSPWithGas(weights, gas, 0));

    gas = {20, 10, 30, 35};
    EXPECT_EQ(95, Backtracking::TSPWithGas(weights, gas, 0));
  }

  {
    weights = {
        {0, 40, 20, 35},
        {40, 0, 30, 100},
        {20, 30, 0, 30},
        {35, 100, 30, 0},
    };

    // { 0, 1, 2, 3 }
    gas = {135, 0, 0, 0};
    EXPECT_EQ(135, Backtracking::TSPWithGas(weights, gas, 0));

    gas = {40, 100, 0, 0};
    EXPECT_EQ(135, Backtracking::TSPWithGas(weights, gas, 0));
  }

  {
    weights = {
        {0, 40, 20, 35},
        {40, 0, 30, 100},
        {20, 30, 0, 30},
        {35, 100, 30, 0},
    };
    gas = {1000, 1000, 1000, 1000, 1000};
    EXPECT_EQ(135, Backtracking::TSPWithGas(weights, gas, 0));

    gas = {10, 1000, 1000, 1000, 1000};
    EXPECT_EQ(INT_MAX, Backtracking::TSPWithGas(weights, gas, 0));

    gas = {40, 1000, 1000, 1000, 1000};
    EXPECT_EQ(135, Backtracking::TSPWithGas(weights, gas, 0));
  }

  {
    weights = {
        {0, 40},
        {40, 0},

    };
    gas = {40, 40};
    EXPECT_EQ(80, Backtracking::TSPWithGas(weights, gas, 0));

    gas = {10, 70};
    EXPECT_EQ(INT_MAX, Backtracking::TSPWithGas(weights, gas, 0));

    gas = {40, 39};
    EXPECT_EQ(INT_MAX, Backtracking::TSPWithGas(weights, gas, 0));
  }

  {
    weights = {
        {0, 20, 42, 35},
        {20, 0, 30, 34},
        {42, 30, 0, 12},
        {35, 34, 12, 0},

    };
    gas = {1000, 1000, 1000, 1000};
    EXPECT_EQ(97, Backtracking::TSPWithGas(weights, gas, 0));

    gas = {97, 0, 0, 0};
    EXPECT_EQ(97, Backtracking::TSPWithGas(weights, gas, 0));

    gas = {42, 42, 13, 0};
    EXPECT_EQ(97, Backtracking::TSPWithGas(weights, gas, 0));
  }

  {
    weights = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0},

    };
    gas = {1000, 1000, 1000, 1000};
    EXPECT_EQ(80, Backtracking::TSPWithGas(weights, gas, 0));

    gas = {79, 1, 0, 0};
    EXPECT_EQ(80, Backtracking::TSPWithGas(weights, gas, 0));

    gas = {78, 1, 0, 1};
    EXPECT_EQ(80, Backtracking::TSPWithGas(weights, gas, 0));

    gas = {76, 1, 1, 2};
    EXPECT_EQ(80, Backtracking::TSPWithGas(weights, gas, 0));
  }

  {
    weights = {
        {0, 10, 15},
        {10, 0, 9},
        {15, 9, 0},

    };
    gas = {10, 9, 15};
    EXPECT_EQ(34, Backtracking::TSPWithGas(weights, gas, 0));

    gas = {9, 10, 15};
    EXPECT_EQ(INT_MAX, Backtracking::TSPWithGas(weights, gas, 0));
  }
}