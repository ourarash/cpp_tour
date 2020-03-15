#ifndef VECTOR_OF_VECTOR_H
#define VECTOR_OF_VECTOR_H
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>

#include <string>
#include <vector>

#include "src/lib/utility.h"

// Uses a Vector of Vector to store the distance data
class DistMatrixGraph {
 public:
  DistMatrixGraph(std::vector<std::vector<int>> &distance)
      : weight_(distance) {}

  // Creates a 2d vector with all elements set to INT_MAX
  // Except the distance of each node to itself is set to 0
  DistMatrixGraph(int n) {
    weight_ = std::vector<std::vector<int>>(n, std::vector<int>(n, INT_MAX));
    for (size_t i = 0; i < n; i++) {
      weight_[i][i] = 0;
    }
  }

  void PrintGraph() {
    for (int i = 0; i < weight_.size(); i++) {
      std::cout << "Vertex: " << i << ", Distance: ";

      PrintIndexIfNonZero(weight_[i]);
    }
  }

  void SetWeight(int i, int j, int distance) { weight_[i][j] = distance; }
  void PrintWeights(std::vector<std::vector<int>> weights);
  void PrintWeights(std::vector<std::vector<long>> weights);

  std::vector<std::vector<long>> FloydWarshall();
  std::vector<long> Dijkstra(int source);
  std::vector<long> DijkstraPriorityQueue(int source);

  std::vector<long> BellmanFord(int source);
  std::vector<long> BellmanFord2D(int source);
  std::map<int, std::set<int>> GetPredecessors();
  std::vector<long> BellmanFordRecursive(int source);
  long BellmanFordRecursiveHelper(int s, int i, int v);

  int FindMinInDButNotInVisited(std::vector<long> &d,
                                std::unordered_set<int> &visited);

  long FloydWarshallRecursiveHelper(int i, int j, int k);

  std::vector<std::vector<long>> FloydWarshallRecursive();

  std::vector<std::vector<int>> weight_;
};

#endif