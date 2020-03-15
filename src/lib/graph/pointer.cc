#include "src/lib/graph/pointer.h"
#include <iostream>

bool PointerGraph::empty() {return false;}

int PointerGraph::size() { return 0; }

bool PointerGraph::HasCycle() {
  for (const auto& node : _nodes) {
    if (node->status == NodeStatus::NotVisited) {
      if (ReachesACycle(node)) {
        return true;
      }
    }
  }
  return false;
};

bool PointerGraph::ReachesACycle(GraphNode* start_node) {
  if (start_node == nullptr) {
    return false;
  }
  if (start_node->status == NodeStatus::Visited) {
    return false;
  }
  std::cout << "start_node->val: " << start_node->val << std::endl;
  if (start_node->status == NodeStatus::Visiting) {
    return true;
  } else {
    start_node->status = NodeStatus::Visiting;
    for (const auto& c : start_node->children) {
      if (ReachesACycle(c)) {
        return true;
      }
    }
    start_node->status = NodeStatus::Visited;
    return false;
  }
};

void PointerGraph::CreateSampleGraph1() {
  for (int i = 0; i < 5; i++) {
    GraphNode* node = new GraphNode(i);
    _nodes.push_back(node);
    if (i > 0) {
      _nodes[i - 1]->children.push_back(node);
    }

    if(i==4){
      _nodes[i]->children.push_back(_nodes[3]);
    }

    if(i==2){
      _nodes[i]->children.push_back(_nodes[1]);
    }
  }
}
