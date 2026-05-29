#include <iostream>
#include <vector>

#include "src/lib/solution.h"

int main() {
  srand(2);

  // Generate random number between 1 and 10
  for (size_t i = 0; i < 10; i++) {
    auto random_number = rand() % 10 + 1;
    std::cout << "random_number: " << random_number << std::endl;
  }
  return 0;
}