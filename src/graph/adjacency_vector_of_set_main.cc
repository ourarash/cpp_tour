#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "src/lib/graph/adjacency_vector_of_set.h"
#include "src/lib/utility.h"

int main() {
  Graph g({Vertex(0, {1, 2}), Vertex(1, {0, 2, 3, 4}), Vertex(3, {1, 2, 4}),
           Vertex(4, {2, 4, 4})});
  std::cout << g.IsEulerWalkable() << std::endl;
}
