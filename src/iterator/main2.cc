#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
  {
    // std::vector<int> v = {1, 2, 3, 4, 5};
    // for (int i = 0; i < v.size(); i++) {
    //   v[i] = v[i] + 10;
    // }

    std::set<int> s = {1, 2, 3, 4, 5};
    // for (int i = 0; i < s.size(); i++) {
    //   s[i] = s[i] + 10;
    // }

    // for (auto it = v.begin(); it != v.end(); ++it) {
    //   *it += *it;
    // }

    // for (auto &n : v) {
    //   n += 10;
    // }

    for (auto n : s) {
      std::cout << "n: " << n << std::endl;
    }

    for ( auto&n : s) {
      n += 10;
    }
  }
  return 0;
}