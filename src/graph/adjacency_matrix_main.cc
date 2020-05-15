#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "src/lib/graph/adjacency_matrix.h"
#include "src/lib/utility.h"

int main() {
  std::vector<std::vector<int>> adjacency = {{0, 1, 1, 0, 0},
                                             {1, 0, 1, 1, 1},
                                             {1, 1, 0, 1, 0},
                                             {0, 1, 1, 0, 1},
                                             {0, 1, 0, 1, 0}};
  Graph g(adjacency);
  std::cout << "g.isEulerWalkable(): " << g.IsEulerWalkable() << std::endl;
  return 0;
}
