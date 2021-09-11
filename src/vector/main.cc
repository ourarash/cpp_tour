#include <iostream>
#include <string>
#include <vector>

#include "src/lib/utility.h"

int main() {
  std::vector<int> a;
  std::cout << "a.size(): " << a.size() << std::endl;
  PrintVector(a);


  a.push_back(1);
  std::cout << "a.size(): " << a.size() << std::endl;
  PrintVector(a);


  a.push_back(2);
  std::cout << "a.size(): " << a.size() << std::endl;
  PrintVector(a);

  std::cout << "a[1]: " << a[1] << std::endl;

  a.pop_back();
  std::cout << "a.size(): " << a.size() << std::endl;
  PrintVector(a);

  // Insert
  std::vector<int> c = {1, 2, 3, 4, 5};
  PrintVector(c);

  c.insert(c.begin(), 0);
  PrintVector(c);

  c.insert(c.begin() + 2, -1);
  PrintVector(c);

  // Erase
  c.erase(c.begin() + 2);
  PrintVector(c);

  {
    int n = 100;
    std::vector<int> v;
    for (int i = 0; i < n; i++) {
      v.push_back(i);
      std::cout << "v[i]: " << v[i] << std::endl;
    }
    PrintVector(v);

    for (auto &n : v) {
      n *= 10;
    }

    PrintVector(v);
  }
  return 0;
}