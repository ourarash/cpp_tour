#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "src/lib/utility.h"

int coinChange(std::vector<int> &coins, int amount) {
  std::vector<int> d(amount + 1);
  d[0] = 0;

  for (int i = 1; i <= amount; i++) {
    d[i] = INT_MAX-1;

    for (auto coin : coins) {
      if (i - coin >= 0) {
        d[i] = std::min(d[i - coin] + 1, d[i]);
      }
    }
  }

  return d[amount] > amount ? -1 : d[amount];
}

int main() {
  std::vector<int> coins = {2};
  int amount = 3;
  int n = coinChange(coins, amount);
  std::cout << "n: " << n << std::endl;
  return 0;
}