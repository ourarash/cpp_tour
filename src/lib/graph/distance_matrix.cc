#include "distance_matrix.h"
#include <algorithm>
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
//-----------------------------------------------------
void DistMatrixGraph::PrintWeights(std::vector<std::vector<int>> weights) {
  PrintWeightsTemplate(weights);
}
//-----------------------------------------------------
void DistMatrixGraph::PrintWeights(std::vector<std::vector<long>> weights) {
  PrintWeightsTemplate(weights);
}
//-----------------------------------------------------
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
      // 0 if i==j, and ∞ if no edge between them
      d[i][j] = weight_[i][j];
    }
  }

  for (int k = 0; k < weight_.size(); k++) {
    for (int i = 0; i < weight_.size(); ++i) {
      for (int j = 0; j < weight_.size(); ++j) {
        d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  return d;
}
//-----------------------------------------------------
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
//-----------------------------------------------------
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
//-----------------------------------------------------
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
//-----------------------------------------------------
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
//-----------------------------------------------------
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

std::map<int, std::set<int>> DistMatrixGraph::GetPredecessors() {
  std::map<int, std::set<int>> pre;
  for (int i = 0; i < weight_.size(); i++) {
    for (int j = 0; j < weight_[0].size(); j++) {
      if (weight_[i][j] < INT_MAX && i != j) {
        pre[j].insert(i);
      }
    }
  }
  return pre;
}
//-----------------------------------------------------
std::vector<long> DistMatrixGraph::BellmanFord(int source) {
  std::vector<long> d(weight_.size(), INT_MAX);
  auto pre = GetPredecessors();

  d[source] = 0;

  for (int i = 0; i < weight_.size() - 1; i++) {
    for (int v = 0; v < weight_.size(); v++) {
      for (int u : pre[v]) {
        std::vector<long> compareList = {d[v], d[u] + weight_[u][v]};
        d[v] = *std::min_element(compareList.begin(), compareList.end());
      }
    }
  }
  return d;
}

//-----------------------------------------------------
// Calculates all d(v,i) for v in V, and i=0 to n
std::vector<long> DistMatrixGraph::BellmanFord2D(int source) {
  std::vector<std::vector<long>> d(weight_.size() - 1,
                                   std::vector<long>(weight_.size()));
  auto pre = GetPredecessors();  // Map of node to its predecessors

  for (int i = 0; i < weight_.size() - 1; i++) {
    for (int v = 0; v < weight_.size(); v++) {
      // Base case
      if (i == 0) {
        d[0][v] = (v == source) ? 0 : INT_MAX;
        continue;
      }

      // non-base case
      d[i][v] = INT_MAX;
      for (int u : pre[v]) {
        std::vector<long> compareList = {d[i][v], d[i - 1][v],
                                         d[i - 1][u] + weight_[u][v]};
        d[i][v] = *std::min_element(compareList.begin(), compareList.end());
      }
    }
  }
  return d[weight_.size() - 2];
}
//-----------------------------------------------------
// s: source
// v: target
// i: maximum path size
// d(i,v) = 0 ;                                     if (i==0 && v==s )
// d(i,v) = infinity ;                              if (i==0 && v!=s )
// d(i,v) = min(d(i-1,v), min(d(i-1, u) + w(u,w)));  otherwise
long DistMatrixGraph::BellmanFordRecursiveHelper(int s, int i, int v) {
  if (i == 0) {
    return (v == s) ? 0 : INT_MAX;
  } else {
    auto pre = GetPredecessors();  // Map of node to its predecessors

    long d = INT_MAX;
    for (auto u : pre[v]) {
      d = std::min(d, BellmanFordRecursiveHelper(s, i - 1, u) + weight_[u][v]);
    }
    return std::min(BellmanFordRecursiveHelper(s, i - 1, v), d);
  }
}
//-----------------------------------------------------
std::vector<long> DistMatrixGraph::BellmanFordRecursive(int source) {
  std::vector<long> d;
  for (int i = 0; i < weight_.size(); i++) {
    d.push_back(BellmanFordRecursiveHelper(source, weight_.size() - 1, i));
  }
  return d;
}
