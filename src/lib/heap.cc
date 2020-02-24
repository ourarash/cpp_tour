#include "heap.h"
#include "utility.h"
#include <iostream>

int Heap::GetParent(int i) {
  if (i == 0) {
    return INT_MAX;
  }
  return data_[(i - 1) / 2];
}
int Heap::GetLeft(int i) {
  if ((2 * i) + 1 >= data_.size()) {
    return INT_MAX;
  }
  return data_[(2 * i) + 1];
}
int Heap::GetRight(int i) {

  if ((2 * i) + 2 >= data_.size()) {
    return INT_MAX;
  }
  return data_[(2 * i) + 2];
}

int Heap::GetParentIndex(int i) {
  if (i == 0) {
    return -1;
  }
  return (i - 1) / 2;
}
int Heap::GetLeftIndex(int i) {
  if ((2 * i) + 1 >= data_.size()) {
    return -1;
  }
  return (2 * i) + 1;
}
int Heap::GetRightIndex(int i) {
  if ((2 * i) + 2 >= data_.size()) {
    return -1;
  }
  return (2 * i) + 2;
}

int Heap::GetSmallestChildIndex(int i) {
  int left_index = GetLeftIndex(i);
  int right_index = GetRightIndex(i);

  if (left_index == -1 && right_index == -1) {
    return -1;
  }

  if (right_index == -1) {
    return left_index;
  }

  int left = GetLeft(i);
  int right = GetRight(i);
  if (left < right) {
    return left_index;
  } else {
    return right_index;
  }
}
//-----------------------------------------------------
int Heap::top() {
  if (data_.size() == 0) {
    return INT_MAX;
  } else {
    return data_[0];
  }
}

//-----------------------------------------------------
void Heap::push(int v) {
  data_.push_back(v);

  TrickleUp(data_.size() - 1);
}
//-----------------------------------------------------
void Heap::TrickleUp(int i) {
  // Fix the min heap property if it is violated
  while (i != 0 && GetParent(i) > data_[i]) {
    Swap(data_[i], data_[GetParentIndex(i)]);
    i = GetParentIndex(i);
  }
}

//-----------------------------------------------------
void Heap::pop() {
  data_[0] = data_.back();
  data_.pop_back();
  TrickleDown(0);
}
//-----------------------------------------------------
void Heap::TrickleDown(int i) {
  // If it's leaf node
  if (GetLeftIndex(i) > data_.size() && GetRightIndex(i) > data_.size()) {
    return;
  }

  int smallest_child_index = GetSmallestChildIndex(i);

  if (data_[i] > data_[smallest_child_index]) {
    Swap(data_[i], data_[smallest_child_index]);
    TrickleDown(smallest_child_index);
  }
}
