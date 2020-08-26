#include <iostream>
#include <vector>

#include "src/lib/solution.h"

int main() {
  Solution solution;

  std::vector<int> inputs = {1, 2, 3, 4, 5};
  int max = solution.FindMax(inputs);
  std::cout << "max: " << max << std::endl;

  inputs = {};
  max = solution.FindMax(inputs);
  std::cout << "max: " << max << std::endl;


  return 0;  // End of a line
}