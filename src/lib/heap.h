#ifndef HEAP_H
#define HEAP_H
#include <vector>

class Heap {
public:
  bool empty() { return data_.empty(); };
  int size() { return data_.size(); }

  int GetParent(int i);
  int GetLeft(int i);
  int GetRight(int i);

  int GetParentIndex(int i);
  int GetLeftIndex(int i);
  int GetRightIndex(int i);
  int GetSmallestChildIndex(int i);

  int top();
  void push(int v);
  void pop();

  void TrickleUp(int i);
  void TrickleDown(int i);
private:
  std::vector<int> data_;
};

#endif