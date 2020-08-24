#include "src/lib/utility.h"
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

bool IsOdd(int i) { return ((i % 2) == 1); }
int MapSum(int value, std::pair<std::string, int> i) {
  return value + i.second;
}

int main() {

  // Accumulate
  {
    std::map<std::string, int> m = {
        {"Tommy", 18}, {"David", 30}, {"John", 18}, {"Ari", 30}};
    auto sum = std::accumulate(m.begin(), m.end(), /*init=*/0,
                               /*binary_op=*/MapSum);
    std::cout << "sum: " << sum << std::endl;
  }
  return 0;
}