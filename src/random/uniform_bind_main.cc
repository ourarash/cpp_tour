#include <iostream>
#include <random>
#include <vector>

#include "src/lib/solution.h"

int main() {
  auto GenRandomValue = std::bind(std::uniform_int_distribution<>(low, high),
                                  std::default_random_engine());

  for (size_t i = 0; i < 10; i++) {
    int index1 = myDist(randGen);

    std::cout << "index1: " << index1 << std::endl;
  }

  return 0;  // End of a line
}