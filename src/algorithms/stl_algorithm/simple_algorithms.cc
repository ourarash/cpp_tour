#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#include "src/lib/utility.h"

int main() {
  // Find
  {
    std::vector<int> v = {12, -2, 0, 13, 3, 5};
    std::vector<int> find_items = {13, 20};

    // Finding from begin to end.
    for (auto e : find_items) {
      
      auto it = std::find(v.begin(), v.end(), e);

      if (it != v.end()) {
        std::cout << "*it: " << *it << std::endl;
        int index = std::distance(v.begin(), it);
        std::cout << "index: " << index << std::endl;
      } else {
        std::cout << "Didn't find." << std::endl;
      }
    }

    // Find from somewhere in the middle.
    auto it2 = v.begin();
    it2++;

    auto it = std::find(it2, v.end(), 12);

    if (it != v.end()) {
      const auto& n = *it;
      std::cout << "Found n: " << n << std::endl;

    } else {
      std::cout << "Didn't find." << std::endl;
    }
  }

  // Sort ascending order
  {
    std::vector<int> v = {12, -2, 0, 13, 3, 5};
    std::sort(v.begin(), v.end());
    Print(v);
  }

  // Sort descending order
  {
    std::vector<int> v = {12, -2, 0, 13, 3, 5};
    std::sort(v.begin(), v.end(), std::greater<int>());
    Print(v);
  }

  // Reverse
  {
    std::vector<int> v = {12, -2, 0, 13, 3, 5};
    std::reverse(v.begin(), v.end());
    Print(v);
  }

  // Count
  {
    std::vector<int> v = {12, -2, 0, 0, 1, 12, 5, 3, 13, 3, 5};
    auto count = std::count(v.begin(), v.end(), 5);
    std::cout << "count: " << count << std::endl;
  }

  // Accumulate
  {
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    int sum = std::accumulate(v.begin(), v.end(), 0);

    std::cout << "sum: " << sum << std::endl;
  }

  return 0;
}