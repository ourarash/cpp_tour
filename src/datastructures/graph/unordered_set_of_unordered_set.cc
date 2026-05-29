#include "src/lib/utility.h"
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

struct Vertex {
  Vertex(int v, std::unordered_set<int> a) : vertex_number(v), adjacents(a) {}
  // This function is used by unordered_set to compare
  bool operator==(const Vertex &rhs) const {
    return (this->vertex_number == rhs.vertex_number);
  }
  int vertex_number;
  std::unordered_set<int> adjacents;
};

struct VertextHashFunction {
  size_t operator()(const Vertex &a) const { return (a.vertex_number); }
};

class Graph {
public:
  Graph(std::unordered_set<Vertex, VertextHashFunction> v) : v_(v) {}
  std::unordered_set<Vertex, VertextHashFunction> v_;
};

int main() {
  Graph v({Vertex(1, {2, 3}), Vertex(2, {1, 3, 4, 5}), Vertex(3, {1, 2, 4}),
           Vertex(4, {2, 4, 4})});
  return 0;
}
