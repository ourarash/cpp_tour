
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

class DynamicProgramming {
 public:
  static int MinimumJumps(std::vector<int> &input, int i);
  static int MinimumJumpsMemo(std::vector<int> &input, int i);
  static int MinimumJumpsMemo_aux(std::unordered_map<int, int> &memo,
                                  std::vector<int> &input, int i);
  //-----------------------------------------------------
  //   We have three coins: {1, 5, 10}. You can use each coin unlimited times.
  //   For a given n, find out how many different ways you can build value n
  //   using the given coins.
  // Example:
  // Input n = 2
  // Output: 1. Explanation: {1, 1}
  static int NumberOfCombinationSums(std::vector<int> &input, int sum);

  static void NumberOfCombinationSums_aux(
      std::vector<int> &input, int sum, int cur_sum,
      std::vector<int> cur_combination, std::set<std::vector<int>> &combinations);
};