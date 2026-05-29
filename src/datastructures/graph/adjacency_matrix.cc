#include "adjacency_matrix.h"

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

bool Graph::IsEulerWalkable() {
  // Create a table to hold degree of each vertex
  std::vector<int> degrees(adjacency_.size());

  // Iterate all edges
  for (int i = 0; i < adjacency_.size(); i++) {
    for (int j = 0; j < adjacency_.size(); j++) {
      if (adjacency_[i][j] == 1) {
        degrees[i]++;
      }
    }
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

template <class T>
void PrintIndexIfNonZero(T input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    if (n != 0) {
      std::cout << count - 1;
    }

    if (count < input.size() && n != 0) {
      std::cout << ", ";
    }
  }
  std::cout << " }" << std::endl;
}

void Graph::PrintGraph() {
  for (int i = 0; i < adjacency_.size(); i++) {
    std::cout << "Vertex: " << i << ", Adjacents: ";
    PrintIndexIfNonZero(adjacency_[i]);
  }
}