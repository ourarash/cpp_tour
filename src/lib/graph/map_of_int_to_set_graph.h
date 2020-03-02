#ifndef MAP_OF_INT_TO_SET_H
#define MAP_OF_INT_TO_SET_H
#include <map>
#include <set>
#include <string>
#include <vector>

class MapSetGraph {
 public:
  MapSetGraph(std::map<int, std::set<int>> &edge_set) : edge_map_(edge_set) {}

  void DFS(int root);
  void BFS(int root);
  
  // A helper function for DFS that carries marks in recursive calls
  void DFS_helper(int root, std::map<int, int> &marks);

  void DFS_helper_with_topo(int root, std::map<int, int> &marks,
                            std::vector<int> &topo_list);

  // Topological sort assuming root doesn't have any incoming edges
  std::vector<int> TopologicalSort(int root);

  void PrintGraph();

  std::map<int, std::set<int>> edge_map_;
};

#endif