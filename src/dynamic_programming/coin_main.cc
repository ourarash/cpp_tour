#include <iostream>
#include <string>
#include <vector>

#include "src/lib/utility.h"

int coinChange(std::vector<int> &coins, int amount) {
  if (amount == 0) {
    return 0;
  }

  if (amount < 0) {
    return -1;
  }

  int min = INT_MAX;
  for (auto coin : coins) {
    int n = coinChange(coins, amount - coin);
    if (n >= 0) {
      min = std::min(n, min);
    }
  }

  if (min >= 0 && min < INT_MAX) {
    return 1 + min;
  } else {
    return -1;
  }
}

int main() {
  std::vector<int> coins = {84,  457, 478, 309, 350, 349,
                            422, 469, 100, 432, 188};
  int amount = 5000;
  int n = coinChange(coins, amount);
  std::cout << "n: " << n << std::endl;
  return 0;
}