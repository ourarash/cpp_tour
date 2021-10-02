#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "src/lib/utility.h"

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};

  // An easy way of iteration
  // Range based loop
  for (const int &n : v) {
    std::cout << "n: " << n << std::endl;
  }

  // If we can index it
  for (int i = 0; i < v.size(); i++) {
    int n = v[i];
    std::cout << "n: " << n << std::endl;
  }

  // General way of iteration
  std::vector<int>::iterator it;
  for (it = v.begin(); it != v.end(); ++it) {
    const int &n = *it;
    std::cout << "n: " << n << std::endl;
  }

  // Using auto
  for (auto it = v.begin(); it != v.end(); ++it) {
    const int &n = *it;
    std::cout << "n: " << n << std::endl;
  }

  // Iterating a Set
  {
    std::set<int> s = {1, 2, 3, 4, 5};
    for (const auto &e : s) {
      std::cout << "e: " << e << std::endl;
    }
  }

  {  // Iterating a Set using iterators
    std::set<int> s = {1, 2, 3, 4, 5};
    for (auto it = s.begin(); it != s.end(); ++it) {
      const int &n = *it;
      std::cout << "n: " << n << std::endl;
    }
  }

  {
    // Insert a number before 3
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (auto it = v.begin(); it != v.end(); ++it) {
      const int &n = *it;
      if (n == 3) {
        v.insert(it, 12);
        break;
      }
    }

    
    for (auto it = v.begin(); it != v.end(); ++it) {
    }

    Print(v);
  }

  {
    // Removing the first odd value:
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (auto it = v.begin(); it != v.end(); ++it) {
      const int &n = *it;
      if (n % 2 == 1) {
        v.erase(it);
        break;
      }
    }
    Print(v);
  }

  return 0;
}
