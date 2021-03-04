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

  // General way of iteration
  std::vector<int>::iterator it;
  for (it = v.begin(); it != v.end(); ++it) {
    const int n = *it;
    std::cout << "n: " << n << std::endl;
  }

  // // If we can index it
  // for (int i = 0; i < v.size(); i++) {
  //   int n = v[i];
  //   std::cout << "n: " << n << std::endl;
  // }

  {  // Set vs vector
    std::vector<int> v = {1, 2, 3, 4, 5};

    for (auto v_it = v.begin(); it != v.end(); ++it) {
      int n = *it;
      *it = *it + 2;
      std::cout << "n: " << n << std::endl;
    }


    for (auto v_it = v.begin(); it != v.end(); ++it) {
      int n = *it;
      std::cout << "n: " << n << std::endl;
    }
  }

  // using auto
  std::set<int> s = {1, 2, 3, 4, 5};
  for (auto it = s.begin(); it != s.end(); ++it) {
    const int &n = *it;
    std::cout << "n: " << n << std::endl;
  }
  Print(s);

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
    Print(v);
  }

  {
    std::vector<int> v = {12, -2, 0, 13, 3, 5};
    std::sort(v.begin(), v.end());
    Print(v);
  }

  {
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (int i = 0; i < v.size(); i++) {
      v[i] = v[i] + 10;
    }

    // Set does not provide subscript operator.
    // std::set<int> s = {1, 2, 3, 4, 5};
    // for (int i = 0; i < s.size(); i++) {
    //   s[i] = s[i] + 10;
    // }

    for (auto &n : v) {
      n += 10;
    }
  }

  return 0;
}

