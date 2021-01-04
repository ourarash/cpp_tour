#include "backtracking.h"

#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "src/lib/utility.h"
//-----------------------------------------------------
std::vector<std::vector<int>> Backtracking::Subsets(std::vector<int> &nums) {
  std::vector<std::vector<int>> result;
  std::vector<int> curResult;
  Backtracking::Subsets_aux(nums, result, curResult, 0);

  return result;
}
void Backtracking::Subsets_aux(std::vector<int> &nums,
                               std::vector<std::vector<int>> &result,
                               std::vector<int> &curResult, int x_index) {
  if (x_index == nums.size()) {
    result.push_back(curResult);
    return;
  }

  // There is only two children
  Backtracking::Subsets_aux(nums, result, curResult, x_index + 1);

  curResult.push_back(nums[x_index]);
  Backtracking::Subsets_aux(nums, result, curResult, x_index + 1);
  curResult.pop_back();
}
//-----------------------------------------------------
std::vector<std::vector<int>> Backtracking::Subsets_2ndSol(
    std::vector<int> &nums) {
  std::vector<std::vector<int>> result;
  std::vector<int> curResult;

  Backtracking::Subsets_2ndSol_aux(nums, result, curResult, 0);

  return result;
}
void Backtracking::Subsets_2ndSol_aux(std::vector<int> &nums,
                                      std::vector<std::vector<int>> &result,
                                      std::vector<int> &curResult, int index) {
  result.push_back(curResult);

  // Generate the branches
  for (int i = index; i < nums.size(); i++) {
    // Update curResult
    curResult.push_back(nums[i]);

    Backtracking::Subsets_2ndSol_aux(nums, result, curResult, i + 1);

    // Reset curResult
    curResult.pop_back();
  }
}
//-----------------------------------------------------
std::vector<std::vector<int>> Backtracking::SubsetsWithDup(
    std::vector<int> &nums) {
  // Sort the input.
  std::sort(nums.begin(), nums.end());
  std::vector<int> curResult;
  std::vector<std::vector<int>> result;
  Backtracking::SubsetsWithDup_aux(nums, result, curResult, 0);
  return result;
}
void Backtracking::SubsetsWithDup_aux(std::vector<int> &nums,
                                      std::vector<std::vector<int>> &result,
                                      std::vector<int> &curResult, int index) {
  // Generate and store the leaf
  result.push_back(curResult);

  // Generate the branches
  for (int i = index; i < nums.size(); i++) {
    // skip duplicates
    if (i > index && nums[i] == nums[i - 1]) {
      continue;
    }
    // Update curResult
    curResult.push_back(nums[i]);

    Backtracking::SubsetsWithDup_aux(nums, result, curResult, i + 1);

    // Reset curResult
    curResult.pop_back();
  }
}
//-----------------------------------------------------
std::vector<std::vector<int>> Backtracking::Permute(std::vector<int> &nums) {
  std::vector<std::vector<int>> result;
  std::vector<int> curResult;
  Backtracking::Permute_aux(nums, result, curResult);

  return result;
}

void Backtracking::Permute_aux(std::vector<int> &nums,
                               std::vector<std::vector<int>> &result,
                               std::vector<int> &curResult) {
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
std::vector<std::vector<int>> Backtracking::PermuteII(std::vector<int> &nums) {
  std::vector<std::vector<int>> result;
  std::sort(nums.begin(), nums.end());
  std::vector<bool> used(nums.size());
  std::vector<int> curResult;
  Backtracking::PermuteII_aux(nums, result, curResult, used);
  return result;
}
void Backtracking::PermuteII_aux(std::vector<int> &nums,
                                 std::vector<std::vector<int>> &result,
                                 std::vector<int> &curResult,
                                 std::vector<bool> &used) {
  // If we get to a leaf, we save the path in result and return return.
  if (curResult.size() == nums.size()) {
    result.push_back(curResult);
    return;
  }

  for (int i = 0; i < nums.size(); i++) {
    // Avoid duplicates
    if (used[i]) {
      continue;
    }

    if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
      continue;
    }

    used[i] = true;
    curResult.push_back(nums[i]);

    Backtracking::PermuteII_aux(nums, result, curResult, used);

    curResult.pop_back();
    used[i] = false;
  }
}
//-----------------------------------------------------
std::vector<std::string> Backtracking::WordBreak(
    std::string &s, std::vector<std::string> &dic) {
  std::vector<std::string> result;
  std::vector<std::string> curResult;
  std::unordered_map<std::string, std::vector<std::string>> memo;
  Backtracking::WordBreak_aux_memo(s, dic, curResult, result, memo);
  return result;
}

void Backtracking::WordBreak_aux(std::string &s, std::vector<std::string> &dic,
                                 std::vector<std::string> &curResult,
                                 std::vector<std::string> &result) {
  if (s.size() == 0) {
    // Join strings in curResult
    std::string joined_string;
    for (int i = 0; i < curResult.size(); i++) {
      joined_string += curResult[i];
      if (i < curResult.size() - 1) {
        joined_string += " ";
      }
    }

    result.push_back(joined_string);
    return;
  }

  for (auto word : dic) {
    // If s starts with word
    if (s.rfind(word, 0) == 0) {
      // Update s and curResult
      auto new_s = s.substr(word.size());
      curResult.push_back(word);

      Backtracking::WordBreak_aux(new_s, dic, curResult, result);

      // Reset curResult
      curResult.pop_back();
    }
  }
}
//-----------------------------------------------------
std::string Backtracking::Join(const std::vector<std::string> &strings) {
  std::string joined_string;
  for (int i = 0; i < strings.size(); i++) {
    joined_string += strings[i];
    if (i < strings.size() - 1) {
      joined_string += " ";
    }
  }

  return joined_string;
}
//-----------------------------------------------------
std::vector<std::string> Backtracking::WordBreak_aux_memo(
    std::string &s, std::vector<std::string> &dic,
    std::vector<std::string> &curResult, std::vector<std::string> &result,
    std::unordered_map<std::string, std::vector<std::string>> &memo) {
  if (memo.count(s) > 0) {
    for (auto &e : memo[s]) {
      auto combined = Backtracking::Join(curResult);
      if (e.size() > 0) {
        combined += " " + e;
      }
      result.push_back(combined);
    }

    return memo[s];
  }

  if (s.size() == 0) {
    result.push_back(Backtracking::Join(curResult));
    return {""};
  }

  for (auto word : dic) {
    // If s starts with word
    if (s.rfind(word, 0) == 0) {
      // Update s and curResult
      auto new_s = s.substr(word.size());
      curResult.push_back(word);

      auto partial =
          Backtracking::WordBreak_aux_memo(new_s, dic, curResult, result, memo);

      for (auto &e : partial) {
        auto combined = word;
        if (e.size() > 0) {
          combined += " " + e;
        }
        memo[s].push_back(combined);
      }

      // Reset curResult
      curResult.pop_back();
    }
  }
  return memo[s];
}

//-----------------------------------------------------
std::vector<std::string> Backtracking::WordBreak_sol2(
    std::string &s, std::vector<std::string> &dic) {
  std::vector<std::string> result;
  std::string curResult;
  std::unordered_map<std::string, std::vector<std::string>> memo;
  Backtracking::WordBreak_sol2_aux_memo(s, dic, curResult, result, memo);
  return result;
}

std::vector<std::string> Backtracking::WordBreak_sol2_aux_memo(
    std::string &s, std::vector<std::string> &dic, std::string &curResult,
    std::vector<std::string> &result,
    std::unordered_map<std::string, std::vector<std::string>> &memo) {
  if (memo.count(s) > 0) {
    for (auto &e : memo[s]) {
      auto combined = curResult;
      if (e.size() > 0) {
        combined += " " + e;
      }
      result.push_back(combined);
    }

    return memo[s];
  }

  if (s.size() == 0) {
    result.push_back(curResult);
    return {""};
  }

  for (auto word : dic) {
    // If s starts with word
    if (s.rfind(word, 0) == 0) {
      // Update s and curResult
      auto new_s = s.substr(word.size());
      int extraSize = 0;
      if (curResult.size() > 0) {
        extraSize++;
        curResult += " ";
      }

      curResult += word;
      extraSize += word.size();

      auto partial = Backtracking::WordBreak_sol2_aux_memo(
          new_s, dic, curResult, result, memo);

      for (auto &e : partial) {
        auto combined = word;
        if (e.size() > 0) {
          combined += " " + e;
        }
        memo[s].push_back(combined);
      }

      // Reset curResult
      curResult.erase(curResult.size() - extraSize, extraSize);
    }
  }
  return memo[s];
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
    // Print2dVector(board);
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
//-----------------------------------------------------
std::vector<std::vector<int>> Backtracking::CombinationSum2(
    std::vector<int> &nums, int target) {
  std::set<std::vector<int>> result;
  std::vector<int> curResult;
  Backtracking::CombinationSum2_aux(nums, target, result, 0, curResult, 0);
  std::vector<std::vector<int>> returnValue(result.begin(), result.end());

  return returnValue;
}

void Backtracking::CombinationSum2_aux(std::vector<int> &nums, int target,
                                       std::set<std::vector<int>> &result,
                                       int curSum, std::vector<int> &curResult,
                                       int index) {
  // If this is an answer leaf.
  if (curSum == target) {
    std::sort(curResult.begin(), curResult.end());
    result.insert(curResult);
    return;
  }

  // Early backtrack.
  if (curSum > target) {
    return;
  }

  // We only explore children from index to the end.
  for (int i = index; i < nums.size(); i++) {
    // Update curResult
    curResult.push_back(nums[i]);

    Backtracking::CombinationSum2_aux(nums, target, result, curSum + nums[i],
                                      curResult, i);

    // Reset curResult
    curResult.pop_back();
  }
}
//-----------------------------------------------------
int Backtracking::UniquePaths(int m, int n) {
  return Backtracking::UniquePaths_aux(m - 1, n - 1);
}

int Backtracking::UniquePaths_aux(int i, int j) {
  if (i == 0 || j == 0) {
    return 1;
  }
  return Backtracking::UniquePaths_aux(i - 1, j) +
         Backtracking::UniquePaths_aux(i, j - 1);
}