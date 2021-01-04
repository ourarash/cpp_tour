
#include "dynamic_programming.h"

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

int DynamicProgramming::MinimumJumps(std::vector<int> &input, int i) {
  if (i == 0) {
    return 0;
  }
  int result = INT_MAX;
  for (int k = 0; k < i; k++) {
    if (k + input[k] >= i) {
      result = std::min(result, DynamicProgramming::MinimumJumps(input, k) + 1);
    }
  }
  return result;
}

int DynamicProgramming::MinimumJumpsMemo(std::vector<int> &input, int i) {
  std::unordered_map<int, int> memo;
  return DynamicProgramming::MinimumJumpsMemo_aux(memo, input, i);
}

int DynamicProgramming::MinimumJumpsMemo_aux(std::unordered_map<int, int> &memo,
                                             std::vector<int> &input, int i) {
  if (i == 0) {
    return 0;
  }
  if (memo.count(i) > 0) {
    std::cout << "SAved!" << std::endl;
    return memo[i];
  }
  int result = INT_MAX;
  for (int k = 0; k < i; k++) {
    if (k + input[k] >= i) {
      result = std::min(
          result, DynamicProgramming::MinimumJumpsMemo_aux(memo, input, k) + 1);
    }
  }
  memo[i] = result;
  return result;
}
//-----------------------------------------------------
int DynamicProgramming::NumberOfCombinationSums(std::vector<int> &input,
                                                int sum) {
  std::set<std::vector<int>> combinations;
  std::vector<int> cur_combination;
  DynamicProgramming::NumberOfCombinationSums_aux(
      input, sum, 0, cur_combination, combinations);
  return combinations.size();
}

void DynamicProgramming::NumberOfCombinationSums_aux(
    std::vector<int> &input, int sum, int cur_sum,
    std::vector<int> cur_combination,
    std::set<std::vector<int>> &combinations) {
  if (cur_sum == sum && cur_combination.size() > 0) {
    std::sort(cur_combination.begin(), cur_combination.end());
    if (std::find(combinations.begin(), combinations.end(), cur_combination) ==
        combinations.end()) {
      combinations.insert(cur_combination);
    }
    return;
  }

  if (cur_sum > sum) {
    return;
  }

  for (auto e : input) {
    auto new_cur_combination = cur_combination;
    new_cur_combination.push_back(e);
    DynamicProgramming::NumberOfCombinationSums_aux(
        input, sum, cur_sum + e, new_cur_combination, combinations);
    new_cur_combination.pop_back();
  }
}