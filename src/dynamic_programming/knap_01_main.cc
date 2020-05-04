#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "src/lib/utility.h"

int knapSack01(std::vector<int> &weights, std::vector<int> &values, int i,
               int w) {
  if (i == -1 || w == 0) {
    return 0;
  }

  // If wi>w, item i is definitely not included
  if (weights[i] > w) {
    return knapSack01(weights, values, i - 1, w);
  }

  return std::max(
      knapSack01(weights, values, i - 1, w),
      values[i] + knapSack01(weights, values, i - 1, w - weights[i]));
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