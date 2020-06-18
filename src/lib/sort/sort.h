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
  static void MergeSortPar(std::vector<int> &input);

  static void MergeSortHelp(std::vector<int> &input, int l, int r);
  static void Merge(std::vector<int> &input, int l, int m, int r);

  static void MergeSortParHelp(std::vector<int> &input, int l, int r);

  static int FindMinIndex(const std::vector<int> &input, int start_index);
  static int GetMinValueAndIncrementItsIndex(std::vector<int> &input,
                                             int &left_index, int &right_index,
                                             const int left_max_index,
                                             const int right_max_index);
  static int Partition(std::vector<int> &input, int low, int high);
  static void QuickSort(std::vector<int> &input) {
    QuickSortImp(input, 0, input.size() - 1);
  }
  static void QuickSortPar(std::vector<int> &input) {
    QuickSortParImp(input, 0, input.size() - 1);
  }

  static void QuickSortImp(std::vector<int> &input, int low, int high);
  static void QuickSortParImp(std::vector<int> &input, int low, int high);

  static void InsertionSort(std::vector<int> &arr) {
    InsertionSortImp(arr, 0, arr.size() - 1);
  }
  static void InsertionSortImp(std::vector<int> &arr, int left, int right);

  static int MedianOfThree(std::vector<int> &v, int a_i, int b_i, int c_i);

  static void IntrosortUtil(std::vector<int> &arr, int begin, int end,
                            int depthLimit);

  static void IntrosortImp(std::vector<int> &arr, int begin, int end);
  static void Introsort(std::vector<int> &arr) {
    IntrosortImp(arr, 0, arr.size() - 1);
  }
  static const int QUICKSORT_THREASHOLD = 10;
  static const int MERGESORT_THREASHOLD = 10;
  static const int INTROSORT_THREASHOLD = 10;
};

#endif