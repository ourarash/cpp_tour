#ifndef FC9DFAA4_708A_495F_A141_B69F7BCF9CAD
#define FC9DFAA4_708A_495F_A141_B69F7BCF9CAD

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

class Graph {
 public:
  Graph(std::vector<std::vector<int>> &adjacency) : adjacency_(adjacency) {}
  bool IsEulerWalkable();
  void PrintGraph();
  std::vector<std::vector<int>> adjacency_;
};

#endif /* FC9DFAA4_708A_495F_A141_B69F7BCF9CAD */
