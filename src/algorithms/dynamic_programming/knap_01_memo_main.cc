#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "src/lib/utility.h"

// memo map works like a cache
std::map<std::pair<int, int>, int> memo;

int knapSack01(std::vector<int> &weights, std::vector<int> &values, int i,
               int w) {
  if (i == -1 || w == 0) {
    return 0;
  }

  if (memo.count(std::make_pair(i, w)) > 0) {
    return memo[std::make_pair(i, w)];
  }

  if (weights[i] > w) {
    memo[std::make_pair(i, w)] = knapSack01(weights, values, i - 1, w);
    return memo[std::make_pair(i, w)];
  }

  memo[std::make_pair(i, w)] = std::max(
             knapSack01(weights, values, i - 1, w),
             values[i] + knapSack01(weights, values, i - 1, w - weights[i]));
  return memo[std::make_pair(i, w)];
}

int main() {
  std::vector<int> values = {60, 100, 120};
  std::vector<int> weights = {10, 20, 30};
  int W = 50;

  // std::vector<int> values = {1, 2, 2, 4, 10};
  // std::vector<int> weights = {1, 2, 1, 12, 4};

  // int W = 15;
  int n = knapSack01(weights, values, values.size() - 1, W);
  std::cout << "n: " << n << std::endl;
  return 0;
}