#include "distance_matrix.h"
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>

#include <string>
#include <vector>

#include "src/lib/utility.h"
template <class T>

void PrintWeightsTemplate(const std::vector<std::vector<T>> &weights) {
  std::cout << "{ " << std::endl;
  for (int i = 0; i < weights.size(); i++) {
    for (int j = 0; j < weights[0].size(); j++) {
      if (weights[i][j] == INT_MAX) {
        std::cout << "∞";

      } else {
        std::cout << weights[i][j];
      }

      if (j < weights[0].size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
  }
  std::cout << " }" << std::endl;
}
void DistMatrixGraph::PrintWeights(std::vector<std::vector<int>> weights) {
  PrintWeightsTemplate(weights);
}

void DistMatrixGraph::PrintWeights(std::vector<std::vector<long>> weights) {
  PrintWeightsTemplate(weights);
}
// Floyd-Warshal Algorithm for finding the shortest distance
// - Can have negative edges
// - Can't have negative cycles
// - All pairs -> O(n^3)
std::vector<std::vector<long>> DistMatrixGraph::FloydWarshall() {
  std::vector<std::vector<long>> d(weight_.size(),
                                   std::vector<long>(weight_.size()));
  // To cover the base case (using no nodes)
  // d is previously initialized to weights_
  for (int i = 0; i < weight_.size(); ++i) {
    for (int j = 0; j < weight_.size(); ++j) {
      d[i][j] = weight_[i][j];
    }
  }

  for (int k = 0; k < weight_.size(); k++) {
    for (int i = 0; i < weight_.size(); ++i) {
      for (int j = 0; j < weight_.size(); ++j) {
        d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
      }
    }
    std::cout << "k: " << k << std::endl;
    PrintWeights(d);
  }

  return d;
}

// Calculates shortest distance between i,j using nodes 0 to k
long DistMatrixGraph::FloydWarshallRecursiveHelper(int i, int j, int k) {
  if (k < 0) {
    return weight_[i][j];
  } else {
    return std::min(FloydWarshallRecursiveHelper(i, j, k - 1),
                    FloydWarshallRecursiveHelper(i, k, k - 1) +
                        FloydWarshallRecursiveHelper(k, j, k - 1));
  }
}

std::vector<std::vector<long>> DistMatrixGraph::FloydWarshallRecursive() {
  std::vector<std::vector<long>> d(weight_.size(),
                                   std::vector<long>(weight_.size()));
  // Find all pair distances
  for (int i = 0; i < weight_.size(); ++i) {
    for (int j = 0; j < weight_.size(); ++j) {
      d[i][j] = FloydWarshallRecursiveHelper(i, j, weight_.size() - 1);
    }
  }
  return d;
}

// Finds the minimum value in d that is not in visited
int DistMatrixGraph::FindMinInDButNotInVisited(
    std::vector<long> &d, std::unordered_set<int> &visited) {
  // Find min
  int u;
  int min = INT_MAX;

  for (int i = 0; i < d.size(); i++) {
    if (find(visited.begin(), visited.end(), i) != visited.end()) {
      continue;
    }
    int e = d[i];
    if (min > e) {
      min = e;
      u = i;
    }
  }

  return u;
}

std::vector<long> DistMatrixGraph::Dijkstra(int source) {
  std::unordered_set<int> visited;
  std::vector<long> d(weight_.size());
  for (int i = 0; i < weight_.size(); i++) {
    d[i] = weight_[source][i];
  }

  visited.insert(source);
  while (visited.size() < weight_.size()) {
    // Find minimum non visited
    int u = FindMinInDButNotInVisited(d, visited);
    visited.insert(u);
    // Relax
    for (int i = 0; i < weight_.size(); i++) {
      d[i] = std::min(d[i], d[u] + weight_[u][i]);
    }
  }
  return d;
}

std::vector<long> DistMatrixGraph::DijkstraPriorityQueue(int source) {
  // Queue of pairs of (distance, node number)
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      q;
  std::vector<long> d(weight_.size(), INT_MAX);
  d[source] = 0;

  q.push(std::make_pair(0, source));

  while (!q.empty()) {
    // Find minimum
    int u = q.top().second;
    q.pop();

    // Relax distances
    // Rather than decreasing the values in the queue,
    // we just add the updated distance to the queue again.
    for (int j = 0; j < weight_.size(); j++) {
      if (d[j] > d[u] + weight_[u][j]) {
        d[j] = d[u] + weight_[u][j];
        q.push(std::make_pair(d[j], j));
      }
    }
  }
  return d;
}

std::vector<long> DistMatrixGraph::BellmanFord(int source) {
  std::vector<long> d(weight_.size(), INT_MAX);
  d[source] = 0;

  for (int i = 0; i < weight_.size() - 1; i++) {
    for (int u = 0; u < weight_.size(); u++) {
      for (int v = 0; v < weight_.size(); v++) {
        d[v] = std::min(d[v], d[u] + weight_[u][v]);
      }
    }
  }
  return d;
}

// s: source
// v: target
// i: maximum path size
// d(v,i) =0 ;                              if (i==0 && v==s )
// d(v,i) =infinity ;                       if (i==0 && v!=s )
// d(v,i) = min(d[v], d[u] + weight[u][v]); otherwise
long DistMatrixGraph::BellmanFordRecursiveHelper(int s, int v, int i) {
  if (v == s) {
    return 0;
  } else if (i == 0) {
    return INT_MAX;
  } else {
    long d = INT_MAX;
    for (int u = 0; u < weight_.size(); u++) {
      d = std::min(d, BellmanFordRecursiveHelper(s, u, i - 1) + weight_[u][v]);
    }
    return std::min(BellmanFordRecursiveHelper(s, v, i - 1), d);
  }
}

std::vector<long> DistMatrixGraph::BellmanFordRecursive(int source) {
  std::vector<long> d;
  for (int i = 0; i < weight_.size(); i++) {
    d.push_back(BellmanFordRecursiveHelper(source, i, weight_.size() - 1));
    // Print(d);
  }
  return d;
}
