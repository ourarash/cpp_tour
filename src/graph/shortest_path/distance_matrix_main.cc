#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "src/lib/graph/distance_matrix.h"
#include "src/lib/utility.h"

int main() {
  // Create a graph
  DistMatrixGraph g(7);
  g.SetWeight(0, 1, 3);
  g.SetWeight(0, 2, 10);
  g.SetWeight(0, 5, 1);

  g.SetWeight(1, 0, 3);
  g.SetWeight(1, 2, 6);
  g.SetWeight(1, 3, 1);

  g.SetWeight(2, 0, 10);
  g.SetWeight(2, 1, 6);
  g.SetWeight(2, 3, 1);

  g.SetWeight(3, 1, 1);
  g.SetWeight(3, 2, 1);
  g.SetWeight(3, 4, 1);
  g.SetWeight(3, 6, 4);

  g.SetWeight(4, 3, 1);

  g.SetWeight(5, 0, 1);
  g.SetWeight(5, 6, 1);

  g.SetWeight(6, 3, 4);
  g.SetWeight(6, 5, 1);

  g.PrintWeights(g.weight_);

  auto distances = g.FloydWarshall();
  g.PrintWeights(distances);

  auto distances_recursive = g.FloydWarshallRecursive();
  g.PrintWeights(distances_recursive);

  auto e = (distances == distances_recursive);
  std::cout << "e: " << e << std::endl;

  auto distances_dijkstra = g.Dijkstra(0);
  Print(distances_dijkstra);

  auto distances_dijkstra_pq = g.Dijkstra(0);
  Print(distances_dijkstra_pq);

  auto distances_bf = g.BellmanFord(0);
  Print(distances_bf);

  auto distances_bf_recursive = g.BellmanFordRecursive(0);
  Print(distances_bf_recursive);

   auto distances_bf_2d = g.BellmanFord2D(0);
  Print(distances_bf_2d);

  return 0;
}
