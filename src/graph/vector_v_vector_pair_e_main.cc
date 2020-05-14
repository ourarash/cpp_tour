#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "src/lib/graph/vector_v_vector_pair_e.h"
#include "src/lib/utility.h"

int main() {
  std::vector<int> v = {0, 1, 2, 3};
  std::vector<std::pair<int, int>> e = {{1, 3}, {1, 3}, {3, 0}, {3, 0},
                                        {0, 2}, {2, 1}, {2, 3}};
  Graph g(v, e);
  std::cout << g.IsEulerWalkable() << std::endl;
}
