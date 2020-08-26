#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>

class Solution {
 public:
  std::string PrintHelloWorld();

  int FindMax(std::vector<int> &inputs) {
    if (inputs.empty()) {
      return -1;
    }

    int result = INT32_MIN;

    // Range based loop
    for (auto n : inputs) {
      if (n > result) {
        result = n;
      }
    }
    return result;
  }
};

#endif