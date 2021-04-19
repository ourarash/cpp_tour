#ifndef SORT_H
#define SORT_H

#include <vector>

class Search {
 public:
  Search() {}
  static int BinarySearchRecursive(std::vector<int> &nums, int n);
  static int BinarySearchRecursive_aux(std::vector<int> &nums, int n, int l,
                                       int r);
  static int BinarySearchIterative(std::vector<int> &nums, int n);
};

#endif