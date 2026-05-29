#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "src/lib/utility.h"

// class Graph {
//  public:
//   Graph(std::set<int> &v, std::set<std::pair<int, int>> &e) : v_(v), e_(e) {}
//   bool IsEulerWalkable();
//   std::set<int> v_;
//   std::set<std::pair<int, int>> e_;
// };

// bool Graph::IsEulerWalkable(){
//   std::vector<int> inDegrees;

// }

int main() {
  std::set<int> v = {1, 2, 3, 4};
  std::set<std::pair<int, int>> e = {{1, 2}, {2, 4}, {4, 3}, {3, 1}};
  Graph g(v, e);
}
