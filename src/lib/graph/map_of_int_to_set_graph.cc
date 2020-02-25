#include "map_of_int_to_set_graph.h"
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include "src/lib/utility.h"

void MapSetGraph::PrintGraph() {
  for (const auto &v : edge_map_) {
    std::cout << "Vertex: " << v.first << ", Adjacents: ";
    Print(v.second);
  }
}

void MapSetGraph::DFS_helper(int root, std::map<int, int> &marks) {
  marks[root] = 1;
  std::cout << "visited: " << root << std::endl;
  // Iterate all children
  for (const int child : edge_map_[root]) {
    // Visit unmarked ones
    if (marks[child] != 1) {
      DFS_helper(child, marks);
    }
  }
}

void MapSetGraph::DFS(int root) {
  std::map<int, int> marks;
  DFS_helper(root, marks);
}

void MapSetGraph::DFS_helper_with_topo(int root, std::map<int, int> &marks,
                                       std::vector<int> &topo_list) {
  marks[root] = 1;
  std::cout << "visited: " << root << std::endl;
  // Iterate all children
  for (const int child : edge_map_[root]) {
    // Visit unmarked ones
    if (marks[child] != 1) {
      DFS_helper_with_topo(child, marks, topo_list);
    }
  }
  topo_list.push_back(root);
}

std::vector<int> MapSetGraph::TopologicalSort(int root) {
  std::vector<int> topo_list;
  std::map<int, int> marks;

  DFS_helper_with_topo(root, marks, topo_list);
  return topo_list;
}

void MapSetGraph::BFS(int root) {
  std::map<int, int> marks;
  std::queue<int> q;

  q.push(root);
  marks[root] = 1;
  std::cout << "visited: " << root << std::endl;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto &n : edge_map_[cur]) {
      if (!marks[n]) {
        marks[n] = 1;
        std::cout << "visited: " << n << std::endl;

        q.push(n);
      }
    }
  }
}
