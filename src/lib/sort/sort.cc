
#include "sort.h"
// #include <ranges>

#include <algorithm>
#include <cmath>
#include <future>
#include <iostream>
#include <vector>

template <class T>
void Swap(T &i, T &j) {
  T temp = i;
  i = j;
  j = temp;
}

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

// void Sort::SelectionSort(std::vector<int> &input) {
//   int i, j, min_idx;

//   // One by one move boundary of unsorted subarray
//   for (i = 0; i < input.size() - 1; i++) {
//     // Find the minimum element in unsorted array
//     min_idx = i;
//     for (j = i + 1; j < input.size(); j++)
//       if (input[j] < input[min_idx]) {
//         min_idx = j;
//       }

//     // Swap the found minimum element with the first element
//     Swap(input[min_idx], input[i]);
//   }
// }

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

int Sort::GetMinValueAndIncrementItsIndex(std::vector<int> &input,
                                          int &left_index, int &right_index,
                                          const int left_max_index,
                                          const int right_max_index) {
  if (left_index > left_max_index) {
    return input[right_index++];
  }
  if (right_index > right_max_index) {
    return input[left_index++];
  }
  if (input[left_index] <= input[right_index]) {
    return input[left_index++];
  } else {
    return input[right_index++];
  }
}

void Sort::Merge(std::vector<int> &input, int l, int m, int r) {
  // We only copy from l to r (including r)
  std::vector<int> input_copy(input.begin() + l, input.begin() + r + 1);

  int left_index = 0;
  int right_index = m + 1 - l;  // adjust m+1 by subtracting l from it
  int left_max_index = m - l;   // Last index of left half
  int right_max_index = r - l;  // Last index of right half
  for (int i = l; i <= r; i++) {
    input[i] = GetMinValueAndIncrementItsIndex(
        input_copy, left_index, right_index, left_max_index, right_max_index);
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

void Sort::MergeSortParHelp(std::vector<int> &input, int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;

    // Sort first and second halves
    // We do multithreading if the size is big enough
    if (r - l > MERGESORT_THREASHOLD) {
      auto t1 = std::thread(MergeSortParHelp, std::ref(input), l, m);
      auto t2 = std::thread(MergeSortParHelp, std::ref(input), m + 1, r);
      t1.join();
      t2.join();
    } else {
      MergeSortHelp(input, l, m);
      MergeSortHelp(input, m + 1, r);
    }
    Merge(input, l, m, r);
  }
}

// Calls MergeSortHelp with l=0, r=input.size() -1
void Sort::MergeSortPar(std::vector<int> &input) {
  MergeSortParHelp(input, 0, int(input.size() - 1));
}

//-----------------------------------------------------
void Sort::InsertionSortImp(std::vector<int> &arr, int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    int key = arr[i];
    int j = i - 1;

    /* Move elements of arr[0..i-1], that are
       greater than key, to one position ahead
       of their current position */
    while (j >= left && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }

  return;
}

// int Sort::Partition(std::vector<int> &input, int low, int high) {
//   // int pivot = input[high];  // pivot
//   int pivot_index = MedianOfThree(input, low, (low + high) / 2, high);
//   int pivot = input[pivot_index];

//   int i = (low - 1);  // Index of smaller element

//   for (int j = low; j <= high - 1; j++) {
//     // If current element is smaller than the pivot
//     if (input[j] < pivot) {
//       i++;  // increment index of smaller element
//       Swap(input[i], input[j]);
//     }
//   }
//   Swap(input[i + 1], input[high]);
//   return (i + 1);
// }

int Sort::Partition(std::vector<int> &input, int low, int high) {
  // int median_index = MedianOfThree(input, low, (low + high) / 2, high);
  int pivot = input[(high + low) / 2];
  // int pivot = input[median_index];

  int i = low;
  int j = high;
  while (true) {
    while (input[i] < pivot) {
      i++;
    }

    while (input[j] > pivot) {
      j--;
    }

    if (i >= j) {
      return j;
    }
    Swap(input[i], input[j]);
    i = i + 1;
    j = j - 1;
  }
}
/* The main function that implements quickSortImp
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void Sort::QuickSortImp(std::vector<int> &input, int low, int high) {
  if (low < high) {
    /* pi is partitioning index, arr[p] is now
    at right place */
    int pi = Partition(input, low, high);

    // Separately sort elements before
    // partition and after partition
    QuickSortImp(input, low, pi);
    QuickSortImp(input, pi + 1, high);
  }
}

void Sort::QuickSortParImp(std::vector<int> &input, int low, int high) {
  if (low < high) {
    /* pi is partitioning index, arr[p] is now
    at right place */
    int pi = Partition(input, low, high);
    // If the size was high enough, we use multi threading
    if (high - low > QUICKSORT_THREASHOLD) {
      // Separately sort elements before
      // partition and after partition
      auto t1 = std::thread(QuickSortParImp, std::ref(input), low, pi);
      auto t2 = std::thread(QuickSortParImp, std::ref(input), pi + 1, high);
      t1.join();
      t2.join();
    } else {
      QuickSortImp(input, low, pi);
      QuickSortImp(input, pi + 1, high);
    }
  }
}

//-----------------------------------------------------
// A function that find the middle of the
// values pointed by the pointers a, b, c
// and return that pointer
int Sort::MedianOfThree(std::vector<int> &v, int a_i, int b_i, int c_i) {
  int a = v[a_i];
  int b = v[b_i];
  int c = v[c_i];

  // Checking for b
  if ((a < b && b < c) || (c < b && b < a)) {
    return b_i;
  }

  // Checking for a
  else if ((b < a && a < c) || (c < a && a < b)) {
    return a_i;
  }

  else {
    return c_i;
  }
}

void Sort::IntrosortUtil(std::vector<int> &arr, int begin, int end,
                         int depthLimit) {
  // Count the number of elements
  int size = end - begin;

  // If partition size is low then do insertion sort
  if (size < 16) {
    InsertionSortImp(arr, begin, end);
    return;
  }

  // If the depth is zero use heapsort
  if (depthLimit == 0) {
    std::make_heap(arr.begin(), arr.end());
    std::sort_heap(arr.begin(), arr.end());
    return;
  }

  // Else use a median-of-three concept to
  // find a good pivot
  int partitionPoint = Partition(arr, begin, end);

  // Swap the values pointed by the two pointers
  // Swap(arr[pivot], arr[end]);

  // Perform Quick Sort
  // int partitionPoint = Partition(arr, begin, end);
  if (size > INTROSORT_THREASHOLD) {
    auto t1 = std::thread(IntrosortUtil, std::ref(arr), begin, partitionPoint,
                          depthLimit - 1);
    auto t2 = std::thread(IntrosortUtil, std::ref(arr), partitionPoint + 1, end,
                          depthLimit - 1);
    t1.join();
    t2.join();
  } else {
    IntrosortUtil(arr, begin, partitionPoint, depthLimit - 1);
    IntrosortUtil(arr, partitionPoint + 1, end, depthLimit - 1);
  }
  return;
}

/* Implementation of introsort*/
void Sort::IntrosortImp(std::vector<int> &arr, int begin, int end) {
  int depthLimit = (end - begin) * std::log(end - begin);
  // int depthLimit = 20;

  // Perform a recursive Introsort
  IntrosortUtil(arr, begin, end, depthLimit);

  return;
}
