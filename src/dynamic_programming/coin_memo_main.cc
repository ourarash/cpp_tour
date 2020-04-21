#include <iostream>
#include <unordered_map>

#include <string>
#include <vector>

#include "src/lib/utility.h"

// memo map works like a cache
std::unordered_map<int, int> memo;

int coinChange(std::vector<int> &coins, int amount) {
  if (amount == 0) {
    return 0;
  }

  if (amount < 0) {
    return -1;
  }

  if (memo.count(amount) > 0) {
    return memo[amount];
  }

  int min = INT_MAX;
  for (auto coin : coins) {
    int n = coinChange(coins, amount - coin);
    if (n >= 0) {
      min = std::min(n, min);
    }
  }

  if (min >= 0 && min < INT_MAX) {
    memo[amount] = 1 + min;
  } else {
    memo[amount] = -1;
  }

  return memo[amount];
}

int main() {
  std::vector<int> coins = {84,  457, 478, 309, 350, 349,
                            422, 469, 100, 432, 188};
  int amount = 60993;
  int n = coinChange(coins, amount);
  std::cout << "n: " << n << std::endl;
  return 0;
}