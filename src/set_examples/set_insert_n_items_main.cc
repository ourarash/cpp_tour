#include "src/lib/utility.h"
#include "src/lib/vector_union.h"

#include <iostream>
#include <set>
#include <string>
#include <vector>

std::set<int> InsertInSet(const std::vector<int> &v) {
  std::set<int> s;

  for (const &n : v) {
    s.insert(n);
  }
}

int main() {

  std::vector<int> v = {1, 2, 3, -1, 33, -5, 1, 5};

  return 0;
}