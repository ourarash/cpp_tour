#include "src/lib/utility.h"
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {

  // std::vector<int> v = {1, 2, 3, 4, 5};

  // // An easy way of iteration
  // for (int n : v) {
  //   std::cout << "n: " << n << std::endl;
  // }

  // // General way of iteration
  // std::vector<int>::iterator it;
  // for (it = v.begin(); it != v.end(); ++it) {
  //   int n = *it;
  //   std::cout << "n: " << n << std::endl;
  // }

  // // If we can index it
  // for (int i = 0; i < v.size(); i++) {
  //   int n = v[i];
  //   std::cout << "n: " << n << std::endl;
  // }

  // { // Set vs vector
  //   std::vector<int> v = {1, 2, 3, 4, 5};
  //   std::vector<int>::iterator v_it;
  //   for (it = v.begin(); it != v.end(); ++it) {
  //     int n = *it;
  //     std::cout << "n: " << n << std::endl;
  //   }
  //   std::set<int> s = {1, 2, 3, 4, 5};
  //   std::set<int>::iterator s_it;
  //   for (s_it = s.begin(); s_it != s.end(); ++s_it) {
  //     int n = *s_it;
  //     std::cout << "n: " << n << std::endl;
  //   }
  // }

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
  return 0;
}