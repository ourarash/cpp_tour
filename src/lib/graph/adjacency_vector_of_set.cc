#include "adjacency_vector_of_set.h"

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

bool Graph::IsEulerWalkable() {
  // Create a table to hold degree of each vertex
  std::vector<int> degrees(v_.size());

  // Iterate vertices
  for (auto v : v_) {
    degrees[v.vertex_number] = v.adjacents.size();
  }

  // Iterate through degree table and count the number of odd ones

  int countOdds = 0;

  for (auto d : degrees) {
    if (d % 2 == 1) {
      countOdds++;
    }
  }
  return (countOdds == 0 || countOdds == 2);
}
