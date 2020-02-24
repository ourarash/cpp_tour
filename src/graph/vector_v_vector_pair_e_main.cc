#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "src/lib/utility.h"

class Graph {
 public:
  Graph(std::vector<int> v, std::vector<std::pair<int, int>> e)
      : v_(v), e_(e) {}

  void PrintGraph() {
    for (const auto &v : v_) {
      std::cout << "Vertex: " << v << ", Adjacents: {";
      for (const auto &e : e_) {
        if (e.first == v) {
          std::cout << e.second << ", ";
        }
      }
      std::cout << "}" << std::endl;
    }
  }

  std::vector<int> v_;
  std::vector<std::pair<int, int>> e_;
};

int main() {
  std::vector<int> v = {1, 2, 3, 4};
  std::vector<std::pair<int, int>> e = {{1, 2}, {2, 4}, {4, 3}, {3, 1}};
  Graph g(v, e);
  g.PrintGraph();
}
