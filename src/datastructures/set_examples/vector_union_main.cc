#include "src/lib/utility.h"
#include "src/lib/vector_union.h"

#include <iostream>
#include <set>
#include <string>
#include <vector>

// Find union of two vectors
int main() {
  VectorUnionSolution s;
  std::vector<int> a = {1, 2, 3}, b = {3, 54, 6};
  auto r = s.Calculate(a, b);
  PrintVector(r);
  return 0;
}