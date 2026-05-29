#include <iostream>
#include <random>
#include <vector>

#include "src/lib/solution.h"

int main() {
  // std::bind glues a distribution and an engine into a single callable that
  // produces a new value each time it's invoked.
  constexpr int low = 0;
  constexpr int high = 100;
  auto GenRandomValue = std::bind(std::uniform_int_distribution<>(low, high),
                                  std::default_random_engine());

  for (size_t i = 0; i < 10; i++) {
    int value = GenRandomValue();
    std::cout << "value: " << value << std::endl;
  }

  return 0;
}