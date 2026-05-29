#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


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
  std::vector<int> values = {1, 10, 15, 20};
  std::vector<int> weights = {1, 10, 15, 15};
  int w = 25;

  
  int n = knapSack01(weights, values, values.size() - 1, w);
  std::cout << "n: " << n << std::endl;
  return 0;
}