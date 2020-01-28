#include "vector_union.h"
#include <set>
std::vector<int> VectorUnionSolution::Calculate(const std::vector<int> &a,
                                                const std::vector<int> &b) {
  std::vector<int> r;
  std::set<int> my_set;
  for (auto n : a) {
    my_set.insert(n);
  }

  for (auto n : b) {
    my_set.insert(n);
  }

  for (auto &n : my_set) {
    r.push_back(n);
  }

  return r;
}
