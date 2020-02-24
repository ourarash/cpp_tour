#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "src/lib/utility.h"

// Uses a Vector of Vector to store the adjacency data
class Graph {
 public:
  Graph(std::vector<std::vector<int>> &adjacency) : adjacency_(adjacency) {}

  void PrintGraph() {
    for (int i = 0; i < adjacency_.size(); i++) {
      std::cout << "Vertex: " << i << ", Adjacents: ";

      PrintIndexIfNonZero(adjacency_[i]);
    }
  }

  std::vector<std::vector<int>> adjacency_;
};

int main() {
  std::vector<std::vector<int>> adjacency = {{0, 1, 1, 0, 0},
                                             {1, 0, 1, 1, 1},
                                             {1, 1, 0, 1, 0},
                                             {0, 1, 1, 0, 1},
                                             {0, 1, 0, 1, 0}};
  Graph g(adjacency);
  g.PrintGraph();
  return 0;
}
