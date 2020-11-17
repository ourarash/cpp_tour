#include <iostream>
#include <string>
#include <vector>

#include "src/lib/utility.h"

class Backtracking {
 public:
  // Permutations
  static std::vector<std::vector<int>> Permute(std::vector<int> &nums);
  static void Permute_aux(std::vector<int> &nums,
                          std::vector<std::vector<int>> &result,
                          std::vector<int> curResult);

  // Eight queen
  static std::vector<std::vector<std::vector<int>>> SolveNQueen(int n);
  static void SolveNQueen(std::vector<std::vector<int>> &board, int j, int n);
  static bool CanPlaceQueen(std::vector<std::vector<int>> &board, int row,
                            int col);
  static void SolveNQueen_aux(
      std::vector<std::vector<std::vector<int>>> &solutions,
      std::vector<std::vector<int>> &board, int j, int n);
};