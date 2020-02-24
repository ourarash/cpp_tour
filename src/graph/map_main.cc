#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "src/lib/utility.h"

class Graph {
 public:
  Graph(std::map<int, std::set<int>> &vertices) : v_(vertices) {}
  void PrintGraph() {
    for (const auto &v : v_) {
      std::cout << "Vertex: " << v.first << ", Adjacents: ";
      Print(v.second);
    }
  }

  std::map<int, std::set<int>> v_;
};

int main() {
  std::map<int, std::set<int>> vertices{
      {1, {2, 3}}, 
      {2, {1, 3, 4, 5}}, 
      {3, {1, 2, 4}}, 
      {4, {2, 4}}
  };
  Graph g(vertices);
  g.PrintGraph();
  return 0;
}
