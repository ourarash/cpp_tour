#include "src/lib/backtracking/backtracking.h"

#include <vector>

#include "gtest/gtest.h"
TEST(BacktrackingTest, Subsets_T1) {
  std::vector<int> in{0, 1, 2};
  std::vector<std::vector<int>> expected{{},  {2},    {1},    {1, 2},
                                         {0}, {0, 2}, {0, 1}, {0, 1, 2}};
  auto actual = Backtracking::Subsets(in);

  EXPECT_EQ(actual, expected);
}
TEST(BacktrackingTest, Subsets_T2) {
  std::vector<int> in{0, 1};
  std::vector<std::vector<int>> expected{{}, {1}, {0}, {0, 1}};
  auto actual = Backtracking::Subsets(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, Subsets_2ndSol_T1) {
  std::vector<int> in{0, 1, 2};
  std::vector<std::vector<int>> expected{{},     {0}, {0, 1}, {0, 1, 2},
                                         {0, 2}, {1}, {1, 2}, {2}};
  auto actual = Backtracking::Subsets_2ndSol(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, Subsets_2ndSol_T2) {
  std::vector<int> in{0, 1};
  std::vector<std::vector<int>> expected{{}, {0}, {0, 1}, {1}};
  auto actual = Backtracking::Subsets_2ndSol(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, SubsetsWithDup_T1) {
  std::vector<int> in{1, 2, 2};
  std::vector<std::vector<int>> expected{{},        {1}, {1, 2},
                                         {1, 2, 2}, {2}, {2, 2}};
  auto actual = Backtracking::SubsetsWithDup(in);

  EXPECT_EQ(actual, expected);
}
TEST(BacktrackingTest, SubsetsWithDup_T2) {
  std::vector<int> in{1, 1, 2, 2};
  std::vector<std::vector<int>> expected{
      {}, {1}, {1, 1}, {1, 1, 2}, {1, 1, 2, 2}, {1, 2}, {1, 2, 2}, {2}, {2, 2}};
  auto actual = Backtracking::SubsetsWithDup(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, Permute) {
  std::vector<int> in{1, 2, 3};
  std::vector<std::vector<int>> expected{{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                         {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
  auto actual = Backtracking::Permute(in);

  EXPECT_EQ(actual, expected);
}

TEST(BacktrackingTest, PermuteII) {
  std::vector<int> in{1, 1, 3};
  std::vector<std::vector<int>> expected{{1, 1, 3}, {1, 3, 1}, {3, 1, 1}};
  auto actual = Backtracking::PermuteII(in);

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
