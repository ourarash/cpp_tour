
#include "sort.h"
#include <iostream>
#include <vector>
#include "src/lib/utility.h"

int Sort::FindMinIndex(const std::vector<int> &input, int start_index) {
  int min_index = start_index;
  int cur_min = input[start_index];
  for (int i = start_index; i < input.size(); i++) {
    if (input[i] < cur_min) {
      cur_min = input[i];
      min_index = i;
    }
  }
  return min_index;
}

void Sort::SelectionSort(std::vector<int> &input) {
  for (int i = 0; i < int(input.size() - 1); i++) {
    int min_index = FindMinIndex(input, i);
    Swap(input[i], input[min_index]);
  }
}

void Sort::BubbleSort(std::vector<int> &input) {
  bool go;
  do {
    go = false;
    for (int i = 0; i < int(input.size() - 1); i++) {
      if (input[i] > input[i + 1]) {
        Swap(input[i], input[i + 1]);
        go = true;
      }
    }
  } while (go);
}

void Sort::BubbleSortImproved(std::vector<int> &input) {
  int n = input.size();

  for (int i = 0; i < n - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < n - 1 - i; j++) {
      if (input[j] > input[j + 1]) {
        Swap(input[j], input[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

int Sort::GetMinValueAndIncrementItsIndex(std::vector<int> &input, int l, int m,
                                          int r, int &left_index,
                                          int &right_index) {
  if (left_index > m) {
    return input[right_index++];
  }
  if (right_index > r) {
    return input[left_index++];
  }
  if (input[left_index] <= input[right_index]) {
    return input[left_index++];
  } else {
    return input[right_index++];
  }
}

void Sort::Merge(std::vector<int> &input, int l, int m, int r) {
  auto input_copy = input;
  int left_index = l;
  int right_index = m + 1;
  for (int i = l; i <= r; i++) {
    input[i] = GetMinValueAndIncrementItsIndex(input_copy, l, m, r, left_index,
                                               right_index);
  }
}

// l: first index, r: last index (included)
void Sort::MergeSortHelp(std::vector<int> &input, int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;

    // Sort first and second halves
    MergeSortHelp(input, l, m);
    MergeSortHelp(input, m + 1, r);

    Merge(input, l, m, r);
  }
}

// Calls MergeSortHelp with l=0, r=input.size() -1
void Sort::MergeSort(std::vector<int> &input) {
  MergeSortHelp(input, 0, int(input.size() - 1));
}
