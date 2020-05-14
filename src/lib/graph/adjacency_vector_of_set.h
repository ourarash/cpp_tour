#ifndef D90B5B66_BEE3_4C49_90C9_6047CD8ABD19
#define D90B5B66_BEE3_4C49_90C9_6047CD8ABD19

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
  Graph(std::vector<Vertex> v) : v_(v) {}
  bool IsEulerWalkable();
  std::vector<Vertex> v_;
};
#endif /* D90B5B66_BEE3_4C49_90C9_6047CD8ABD19 */
