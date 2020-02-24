#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>

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
    }
  }
  return 0;
}