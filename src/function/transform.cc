#include "src/lib/utility.h"
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

int IncrementByTen(int a) { return a + 10; }
int MathFunction(int a) { return a ^ 2 + 10; }

int main() {

  std::vector<int> inputs = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  std::vector<int> outputs(inputs.size());

  // Increment all of them
  std::transform(inputs.begin(), inputs.end(), outputs.begin(), IncrementByTen);

  Print(outputs);

  std::transform(inputs.begin(), inputs.end(), outputs.begin(), MathFunction);
  Print(outputs);

  return 0;
}