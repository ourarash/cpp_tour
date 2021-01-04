#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>

#include "src/lib/utility.h"

class Backtracking {
 public:
  // Subsets
  static std::vector<std::vector<int>> Subsets(std::vector<int> &nums);
  static void Subsets_aux(std::vector<int> &nums,
                          std::vector<std::vector<int>> &result,
                          std::vector<int> &curResult, int x_index);

  static std::vector<std::vector<int>> Subsets_2ndSol(std::vector<int> &nums);
  static void Subsets_2ndSol_aux(std::vector<int> &nums,
                                 std::vector<std::vector<int>> &result,
                                 std::vector<int> &curResult, int index);

  static std::vector<std::vector<int>> SubsetsWithDup(std::vector<int> &nums);
  static void SubsetsWithDup_aux(std::vector<int> &nums,
                                 std::vector<std::vector<int>> &result,
                                 std::vector<int> &curResult, int index);

  // Permutations
  static std::vector<std::vector<int>> Permute(std::vector<int> &nums);
  static void Permute_aux(std::vector<int> &nums,
                          std::vector<std::vector<int>> &result,
                          std::vector<int> &curResult);

  // Permutations II
  static std::vector<std::vector<int>> PermuteII(std::vector<int> &nums);
  static void PermuteII_aux(std::vector<int> &nums,
                            std::vector<std::vector<int>> &result,
                            std::vector<int> &curResult,
                            std::vector<bool> &used);

  // Word break II
  static std::vector<std::string> WordBreak(std::string &s,
                                            std::vector<std::string> &dic);
  static void WordBreak_aux(std::string &s, std::vector<std::string> &dic,
                            std::vector<std::string> &curResult,
                            std::vector<std::string> &result);

  static std::vector<std::string> WordBreak_aux_memo(
      std::string &s, std::vector<std::string> &dic,
      std::vector<std::string> &curResult, std::vector<std::string> &result,
      std::unordered_map<std::string, std::vector<std::string>> &memo);
  static std::string Join(const std::vector<std::string> &strings);

  // Word break II solution 2
  static std::vector<std::string> WordBreak_sol2(std::string &s,
                                                 std::vector<std::string> &dic);
  static std::vector<std::string> WordBreak_sol2_aux_memo(
      std::string &s, std::vector<std::string> &dic,
      std::string &curResult, std::vector<std::string> &result,
      std::unordered_map<std::string, std::vector<std::string>> &memo);

  // Eight queen
  static std::vector<std::vector<std::vector<int>>> SolveNQueen(int n);
  static void SolveNQueen(std::vector<std::vector<int>> &board, int j, int n);
  static bool CanPlaceQueen(std::vector<std::vector<int>> &board, int row,
                            int col);
  static void SolveNQueen_aux(
      std::vector<std::vector<std::vector<int>>> &solutions,
      std::vector<std::vector<int>> &board, int j, int n);

  // Combination sum
  static std::vector<std::vector<int>> CombinationSum2(std::vector<int> &nums,
                                                      int target);
  static void CombinationSum2_aux(std::vector<int> &nums, int target,
                                 std::set<std::vector<int>> &result,
                                 int curSum, std::vector<int> &curResult,
                                 int index);
  // Unique paths
  static int UniquePaths(int m, int n);
  static int UniquePaths_aux(int m, int n);
};