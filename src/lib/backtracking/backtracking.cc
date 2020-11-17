#include "backtracking.h"

#include <iostream>
#include <string>
#include <vector>

#include "src/lib/utility.h"
//-----------------------------------------------------
std::vector<std::vector<int>> Backtracking::Permute(std::vector<int> &nums) {
  std::vector<std::vector<int>> result;

  Backtracking::Permute_aux(nums, result, {});

  return result;
}

void Backtracking::Permute_aux(std::vector<int> &nums,
                               std::vector<std::vector<int>> &result,
                               std::vector<int> curResult) {
  // If we get to a leaf, we save the path in result and return return.
  if (curResult.size() == nums.size()) {
    result.push_back(curResult);
    return;
  }

  // Generate the branches
  for (int i = 0; i < nums.size(); i++) {
    // Avoid duplicates and backtrack
    if (find(curResult.begin(), curResult.end(), nums[i]) != curResult.end()) {
      continue;
    }

    // Recursive DFS-like call
    std::vector<int> nextCurResult = curResult;
    nextCurResult.push_back(nums[i]);
    Backtracking::Permute_aux(nums, result, nextCurResult);
  }
}
//-----------------------------------------------------
std::vector<std::vector<std::vector<int>>> Backtracking::SolveNQueen(int n) {
  std::vector<std::vector<int>> board(n, std::vector<int>(n));
  std::vector<std::vector<std::vector<int>>> solutions;

  Backtracking::SolveNQueen_aux(solutions, board, 0, n);
  return solutions;
}

bool Backtracking::CanPlaceQueen(std::vector<std::vector<int>> &board, int row,
                                 int col) {
  int i, j;

  /* Check this row on left side */
  for (i = 0; i < col; i++)
    if (board[row][i]) return false;

  /* Check upper diagonal on left side */
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j]) return false;

  /* Check lower diagonal on left side */
  for (i = row, j = col; j >= 0 && i < board.size(); i++, j--)
    if (board[i][j]) return false;

  return true;
}

void Backtracking::SolveNQueen_aux(
    std::vector<std::vector<std::vector<int>>> &solutions,
    std::vector<std::vector<int>> &board, int j, int n) {
  if (j == n) {
    Print2dVector(board);
    solutions.push_back(board);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (Backtracking::CanPlaceQueen(board, i, j)) {
      board[i][j] = 1;

      Backtracking::SolveNQueen_aux(solutions, board, j + 1, n);

      board[i][j] = 0;
    }
  }
}