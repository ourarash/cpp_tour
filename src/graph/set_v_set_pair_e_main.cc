#include "src/lib/utility.h"
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

class Graph {
public:
  Graph(std::set<int> v, std::set<std::pair<int, int>> e) : v_(v), e_(e) {}
  // void Print() { for (auto v:v_){
  //   std::cout << "Vertex: " << v << ", Adjacents: ";
  //   Print(v.adjacents);
  // }}

  std::set<int> v_;
  std::set<std::pair<int, int>> e_;
};

int main() {
  std::set<int> v = {1, 2, 3, 4};
  std::set<std::pair<int, int>> e = {{1, 2}, {2, 4}, {4, 3}, {3, 1}};
  Graph g(v, e);
}
