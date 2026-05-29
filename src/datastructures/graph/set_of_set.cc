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

struct VertextLessThan {
  bool operator()(const Vertex &a, const Vertex &b) const {
    return (a.vertex_number < b.vertex_number);
  }
};

class Graph {
public:
  Graph(std::set<Vertex, VertextLessThan> v) : v_(v) {}
  std::set<Vertex, VertextLessThan> v_;
};

int main() {
  Graph v({Vertex(1, {2, 3}), Vertex(2, {1, 3, 4, 5}), Vertex(3, {1, 2, 4}),
           Vertex(4, {2, 4, 4})});
  return 0;
}
