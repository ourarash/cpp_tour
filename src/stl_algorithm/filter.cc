#include "src/lib/utility.h"
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

bool IsOdd(int i) { return ((i % 2) == 1); }

int main() {

  std::vector<int> inputs = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  std::vector<int> outputs(inputs.size());

  // Increment all of them
  std::copy_if(inputs.begin(), inputs.end(), outputs.begin(), IsOdd);
  Print(outputs);

  std::cout << "outputs.size(): " << outputs.size() << std::endl;

  return 0;
}