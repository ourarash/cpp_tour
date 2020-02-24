#include "src/lib/utility.h"
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

struct Vertex {
  Vertex(int v, std::set<int> a) : vertex_number(v), adjacents(a) {}
  int vertex_number;
  std::set<int> adjacents;
};

class Graph {
public:
  Graph() {}
  Graph(std::vector<Vertex> v) : v_(v) {}
  std::vector<Vertex> v_;
};

int main() {
  Graph g1({Vertex(1, {2, 3}), Vertex(2, {1, 3, 4, 5}), Vertex(3, {1, 2, 4}),
            Vertex(4, {2, 4, 4})});

  Graph g2;
  g2.v_.push_back(Vertex(1, {2, 3}));
  g2.v_.push_back(Vertex(2, {1, 3, 4, 5}));
  g2.v_.push_back(Vertex(3, {1, 2, 4}));
  g2.v_.push_back(Vertex(4, {2, 4, 4}));
  for (const auto &v : g2.v_) {
    std::cout << "Vertex: " << v.vertex_number << ", Adjacents: ";
    Print(v.adjacents);
  }
  return 0;
}
