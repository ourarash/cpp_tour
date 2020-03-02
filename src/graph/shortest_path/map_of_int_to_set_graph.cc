#include "src/lib/graph/map_of_int_to_set_graph.h"
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "src/lib/utility.h"

int main() {
  // DFS
  // {
  //   std::map<int, std::set<int>> vertices{
  //       {0, {1, 2, 5}}, {1, {0, 2, 3}}, {2, {0, 1, 3}}, {3, {1, 2, 4, 6}},
  //       {4, {3}},       {5, {0}},       {6, {3}}};

  //   MapSetGraph g(vertices);
  //   g.PrintGraph();
  //   g.DFS(0);
    
  // }

  // BFS
  {
    std::map<int, std::set<int>> vertices{
        {0, {1, 2, 5}}, {1, {0, 2, 3}}, {2, {0, 1, 3}}, {3, {1, 2, 4, 6}},
        {4, {3}},       {5, {0}},       {6, {3}}};

    MapSetGraph g(vertices);
    g.PrintGraph();
    g.BFS(0);
  }

  // Topo
  // {
  //   std::map<int, std::set<int>> vertices{{0, {1, 2, 5}}, {1, {2, 3}}, {2, {3}},
  //                                         {3, {4, 6}},    {4, {}},     {5, {2}},
  //                                         {6, {}}};

  //   MapSetGraph g(vertices);
  //   g.PrintGraph();
  //   g.DFS(0);
  //   std::vector<int> topo_list = g.TopologicalSort(0);
  //   Print(topo_list);
  // }

  // // Topological Sort
  // {
  //   std::map<int, std::set<int>> vertices{{0, {1, 2, 5}}, {1, {2, 3}}, {2, {3}},
  //                                         {3, {4, 6}},    {4, {}},     {5, {2}},
  //                                         {6, {}}};

  //   MapSetGraph g(vertices);
  //   g.PrintGraph();
  //   std::vector<int> topo_list = g.TopologicalSort(0);
  //   Print(topo_list);
  // }


  return 0;
}
