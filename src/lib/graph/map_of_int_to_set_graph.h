#ifndef MAP_OF_INT_TO_SET_H
#define MAP_OF_INT_TO_SET_H
#include <map>
// #include <pair>
#include <set>
#include <string>
#include <vector>

class MapSetGraph {
 public:
  MapSetGraph(std::map<int, std::set<int>> &em) : edge_map_(em) {}
  MapSetGraph(std::map<int, std::set<int>> &em,
              std::map<std::pair<int, int>, int> &w)
      : weights_(w), edge_map_(em) {}

  void DFS(int root);
  void BFS(int root);

  // A helper function for DFS that carries marks in recursive calls
  void DFS_helper(int root, std::map<int, int> &marks);

  void DFS_helper_with_topo(int root, std::map<int, int> &marks,
                            std::vector<int> &topo_list);

  // Topological sort assuming root doesn't have any incoming edges
  std::vector<int> TopologicalSort(int root);

  void PrintGraph();
  // Removes the edge between u,v
  void RemoveEdge(int u, int v);
  // Adds k intermediate nodes between u,v and
  // sets the edge weight between them to w
  void AddKNodesBetween(int u, int v, int k, int w);
  // Removes all intermediate nodes
  void RemoveAllIntermediateNodes();

  std::map<std::pair<int, int>, int> weights_;
  std::map<int, std::set<int>> edge_map_;
};

#endif