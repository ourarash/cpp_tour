#include "distance_matrix.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
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
    auto res = std::min(FloydWarshallRecursiveHelper(i, j, k - 1),
                        FloydWarshallRecursiveHelper(i, k, k - 1) +
                            FloydWarshallRecursiveHelper(k, j, k - 1));
    return res;
  }
}
//-----------------------------------------------------
// Calculates shortest distance between i,j using nodes 0 to k
long DistMatrixGraph::FloydWarshallRecursiveHelperMemo(
    int i, int j, int k, std::map<std::vector<int>, long> &memo) {
  if (k < 0) {
    return weight_[i][j];
  } else {
    if (memo.count({i, j, k}) > 0) {
      return memo[{i, j, k}];
    }
    memo[{i, j, k}] =
        std::min(FloydWarshallRecursiveHelperMemo(i, j, k - 1, memo),
                 FloydWarshallRecursiveHelperMemo(i, k, k - 1, memo) +
                     FloydWarshallRecursiveHelperMemo(k, j, k - 1, memo));
    return memo[{i, j, k}];
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
std::vector<std::vector<long>> DistMatrixGraph::FloydWarshallRecursiveMemo() {
  std::map<std::vector<int>, long> memo;
  std::vector<std::vector<long>> d(weight_.size(),
                                   std::vector<long>(weight_.size()));
  // Find all pair distances
  for (int i = 0; i < weight_.size(); ++i) {
    for (int j = 0; j < weight_.size(); ++j) {
      d[i][j] =
          FloydWarshallRecursiveHelperMemo(i, j, weight_.size() - 1, memo);
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
//-----------------------------------------------------
// std::vector<long> DistMatrixGraph::shortestPathTopo(int source) {
//   std::vector<long> d(weight_.size(), INT_MAX);
//   d[source] = 0;
//   std::vector<int> sorted = topologicalSortDFS(graph);
//   for (auto n : sorted) {
//     for (int j = 0; j < weight_.size(); j++) {
//       // Relax outgoing edges of n
//       if (weight_[n][j] != INT_MAX) {
//         d[j] = min(d[j], d[n] + weight_[n][j]);
//       }
//     }
//   }
//   return d;
// }
//-----------------------------------------------------
int DistMatrixGraph::TSP5(int start) {
  std::vector<int> cur_path = {start};
  std::vector<int> min_path;
  int min_cost = INT_MAX;
  TSP_aux5(start, start, 0, cur_path, min_cost, min_path);
  std::cout << "min_path:" << std::endl;
  Print(min_path);
  return min_cost;
}
//-----------------------------------------------------
// This version conforms to the template. It also calculates both min_cost and
// min_path.
void DistMatrixGraph::TSP_aux5(int start, int cur_node, int cur_cost,
                               std::vector<int> &cur_path, int &min_cost,
                               std::vector<int> &min_path) {
  // If we are at a leaf, update min_cost and min_path.
  if (cur_path.size() == weight_.size()) {
    int final_cost = cur_cost + weight_[cur_node][start];
    if (final_cost < min_cost) {
      min_cost = final_cost;
      min_path = cur_path;
    }
    return;
  }
  // Early backtracking
  if (cur_cost > min_cost) {
    return;
  }
  // Else, evaluate all children.
  for (int i = 0; i < weight_.size(); i++) {
    if (std::find(cur_path.begin(), cur_path.end(), i) == cur_path.end()) {
      cur_path.push_back(i);

      TSP_aux5(start, i, cur_cost + weight_[cur_node][i], cur_path, min_cost,
               min_path);

      cur_path.pop_back();
    }
  }
}
//-----------------------------------------------------
int DistMatrixGraph::TSP4(int start) {
  std::vector<int> cur_path = {start};
  return TSP_aux(start, start, cur_path);
}
//-----------------------------------------------------
// This version calculates the sum from bottom to top and also conforms to the
// standard backtracking template
int DistMatrixGraph::TSP_aux(int start, int cur_node,
                             std::vector<int> &cur_path) {
  // If we are at a leaf, return the cost of leaf to start.
  if (cur_path.size() == weight_.size()) {
    return weight_[cur_node][start];
  }

  // Else, return the min of TSP among all children of cur_node
  int result = INT_MAX;
  for (int i = 0; i < weight_.size(); i++) {
    if (i != cur_node &&
        std::find(cur_path.begin(), cur_path.end(), i) == cur_path.end()) {
      cur_path.push_back(i);

      int branch_cost = weight_[cur_node][i] + TSP_aux(start, i, cur_path);
      result = std::min(result, branch_cost);

      cur_path.pop_back();
    }
  }
  return result;
}
//-----------------------------------------------------

int DistMatrixGraph::TSP3(int start) {
  std::vector<int> path;
  return TSP_Helper3(start, start, path);
}
//-----------------------------------------------------
// This version calculates the sum from bottom to top
int DistMatrixGraph::TSP_Helper3(int start, int cur_node,
                                 std::vector<int> path) {
  int result = INT_MAX;
  path.push_back(cur_node);

  // If we are at a leaf, return the cost of leaf to start.
  if (path.size() == weight_.size()) {
    return weight_[cur_node][start];
  }

  // Else, return the min of TSP among all children of cur_node
  for (int i = 0; i < weight_.size(); i++) {
    if (i != cur_node && std::find(path.begin(), path.end(), i) == path.end()) {
      result =
          std::min(result, weight_[cur_node][i] + TSP_Helper3(start, i, path));
    }
  }
  return result;
}
//-----------------------------------------------------
int DistMatrixGraph::TSP2(int start) {
  std::vector<int> path;
  return TSP_Helper2(start, start, 0, path);
}
//-----------------------------------------------------
int DistMatrixGraph::TSP_Helper2(int start, int cur_node, int cur_cost,
                                 std::vector<int> path) {
  int result = INT_MAX;
  path.push_back(cur_node);

  // If we are at a leaf, return cur_cost + the cost of leaf to start.
  if (path.size() == weight_.size()) {
    return cur_cost + weight_[cur_node][start];
  }

  // Else, return the min of TSP among all children of cur_node
  for (int i = 0; i < weight_.size(); i++) {
    if (i != cur_node && std::find(path.begin(), path.end(), i) == path.end()) {
      result = std::min(
          result, TSP_Helper2(start, i, cur_cost + weight_[cur_node][i], path));
    }
  }
  return result;
}
//-----------------------------------------------------
int DistMatrixGraph::TSP1(int start) {
  std::vector<int> path;
  int min_cost = INT_MAX;
  return TSP_Helper1(start, start, 0, min_cost, path);
}
//-----------------------------------------------------
// This version tries to keep the min_cost and only visit nodes when the
// cur_cost is less than min_cost
int DistMatrixGraph::TSP_Helper1(int start, int cur_node, int cur_cost,
                                 int &min_cost, std::vector<int> path) {
  int result = INT_MAX;
  path.push_back(cur_node);

  // If we are at a leaf, return cur_cost + the cost of leaf to start.
  if (path.size() == weight_.size()) {
    min_cost = std::min(min_cost, cur_cost + weight_[cur_node][start]);
    return cur_cost + weight_[cur_node][start];
  }

  // Else, return the min of TSP among all children of cur_node
  for (int i = 0; i < weight_.size(); i++) {
    if (i != cur_node && std::find(path.begin(), path.end(), i) == path.end()) {
      if (cur_cost < min_cost) {
        result = std::min(result,
                          TSP_Helper1(start, i, cur_cost + weight_[cur_node][i],
                                      min_cost, path));
      } else {
        std::cout << "cur_cost: " << cur_cost << ", min_cost: " << min_cost
                  << std::endl;
        std::cout << "We saved! i: " << i << std::endl;
        Print(path);
      }
    }
  }
  return result;
}