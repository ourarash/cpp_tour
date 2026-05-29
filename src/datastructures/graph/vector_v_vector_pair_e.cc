#include "vector_v_vector_pair_e.h"

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

bool Graph::IsEulerWalkable() {
  // Create a table to hold degree of each vertex
  std::vector<int> degrees(v_.size());
  
  // Iterate all edges
  for (auto e : e_) {
    degrees[e.first]++;
    degrees[e.second]++;
  }
  int countOdds = 0;

  // Iterate through degree table and count the number of odd ones
  for (auto d : degrees) {
    if (d % 2 == 1) {
      countOdds++;
    }
  }
  return (countOdds == 0 || countOdds == 2);
}

void Graph::PrintGraph() {
  for (const auto v : v_) {
    std::cout << "Vertex: " << v << ", Adjacents: {";
    for (const auto e : e_) {
      if (e.first == v) {
        std::cout << e.second << ", ";
      }
    }
    std::cout << "}" << std::endl;
  }
}
