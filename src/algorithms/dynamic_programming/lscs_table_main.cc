#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "src/lib/utility.h"
// Given an integer array nums, find the contiguous subarray (containing at
// least one number) which has the largest sum and return its sum.

// Example:

// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

// Finds LSCS at index i
int MAX_LSCS(std::vector<int> &input) {
  std::vector<int> d(input.size());
  d[0] = input[0];
  for (int i = 1; i < input.size(); i++) {
    d[i] = std::max(d[i - 1] + input[i], input[i]);
  }
  auto max = std::max_element(d.begin(), d.end());

  return *max;
}

// Driver function
int main() {
  std::vector<int> input = {-2, 1, -3, 4, -1, 2, 1, -5, 3};

  auto max = MAX_LSCS(input);

  std::cout << "max: " << max << std::endl;

  return 0;
}