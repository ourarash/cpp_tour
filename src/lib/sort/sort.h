#ifndef SORT_H
#define SORT_H

#include <vector>

class Sort {
 public:
  Sort() {}
  static void SelectionSort(std::vector<int> &input);
  static void BubbleSort(std::vector<int> &input);
  static void BubbleSortImproved(std::vector<int> &input);

  static void MergeSort(std::vector<int> &input);

  static void MergeSortHelp(std::vector<int> &input, int l, int r);
  static void Merge(std::vector<int> &input, int l, int m, int r);

  static int FindMinIndex(const std::vector<int> &input, int start_index);
  static int GetMinValueAndIncrementItsIndex(std::vector<int> &input,
                                             int &left_index, int &right_index,
                                             const int left_max_index,
                                             const int right_max_index);
};

#endif