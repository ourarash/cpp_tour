#ifndef F92F9E56_8740_4FD4_9259_76E174846CF4
#define F92F9E56_8740_4FD4_9259_76E174846CF4

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

class Graph {
 public:
  Graph(std::vector<int> &v, std::vector<std::pair<int, int>> &e)
      : v_(v), e_(e) {}
  bool IsEulerWalkable();
  void PrintGraph();
  std::vector<int> v_;
  std::vector<std::pair<int, int>> e_;
};
#endif /* F92F9E56_8740_4FD4_9259_76E174846CF4 */
