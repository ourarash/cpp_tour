
#include "search.h"
// #include <ranges>

#include <algorithm>
#include <cmath>
#include <future>
#include <iostream>
#include <vector>

int Search::BinarySearchRecursive(std::vector<int> &nums, int n) {
  return BinarySearchRecursive_aux(nums, n, /*l=*/0, /*r=*/nums.size() - 1);
}

int Search::BinarySearchRecursive_aux(std::vector<int> &nums, int n, int l,
                                      int r) {
  if (l > r) {
    return -1;
  }

  int mid = l + (r - l) / 2;

  if (nums[mid] == n) {
    return mid;
  }

  if (nums[mid] > n) {
    return BinarySearchRecursive_aux(nums, n, l, mid - 1);
  } else {
    return BinarySearchRecursive_aux(nums, n, mid + 1, r);
  }
}

int Search::BinarySearchIterative(std::vector<int> &nums, int n) {
  int l = 0;
  int r = nums.size() - 1;

  while (r >= l) {
    int mid = (r + l) / 2;

    if (nums[mid] == n) {
      return mid;
    } else if (nums[mid] > n) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return -1;
}
