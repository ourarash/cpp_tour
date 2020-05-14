#include "adjacency_vector_of_set.h"

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

bool Graph::IsEulerWalkable() {
  std::vector<int> degrees(v_.size());
  for (auto v : v_) {
    for (auto e : v.adjacents) {
      degrees[v.vertex_number]++;
      degrees[e]++;
    }
  }
  int countOdds = 0;

  for (auto d : degrees) {
    if (d % 2 == 1) {
      countOdds++;
    }
  }
  return (countOdds == 0 || countOdds == 2);
}
