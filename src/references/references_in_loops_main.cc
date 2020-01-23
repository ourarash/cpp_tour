#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<int> my_vector = {1, 2, 3, 4, 5, 6, 7, 8};

  PrintVector(my_vector);

  for (auto n : my_vector) {

    n++;
    std::cout << "n: " << n << std::endl;
  }
  PrintVector(my_vector);

  for (auto &n : my_vector) {
    n *= 10;
  }
  PrintVector(my_vector);

  return 0;
}