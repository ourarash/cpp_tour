#ifndef TREE_H
#define TREE_H
#include <set>
#include <vector>

enum class NodeStatus { NotVisited, Visiting, Visited };

struct GraphNode {
  int val;
  NodeStatus status;
  std::vector<GraphNode *> children;
  GraphNode(int v) : val(v) { status = NodeStatus::NotVisited; }
  GraphNode(int v, std::vector<GraphNode *> &c) : val(v), children(c) {}
};

class PointerGraph {
 public:
  PointerGraph() {}
  // Returns true if a cycle is reachable from start_node
  bool ReachesACycle(GraphNode *start_node);

  // Returns true if the graph has a cycle
  bool HasCycle();

  // Resets the status of all nodes to NodeStatus::NotVisited
  void ResetStatus();

  bool empty();
  int size();
  void CreateSampleGraph1();
  std::vector<GraphNode *> _nodes;
};

#endif