#include "src/lib/sort/sort.h"
#include <functional>
#include <vector>
#include "gtest/gtest.h"

void TestSort(std::function<void(std::vector<int>&)> sort_func) {
  std::vector<int> in;
  std::vector<int> expected;

  // Check empty
  in = {};
  sort_func(in);
  expected = {};
  EXPECT_EQ(expected, in);
  EXPECT_EQ(expected.size(), in.size());

  // Sort array of 1 element
  in = {3};
  sort_func(in);
  expected = {3};
  EXPECT_EQ(expected, in);
  EXPECT_EQ(expected.size(), in.size());

  in = {5, 3, 1, 77, -1};
  sort_func(in);
  expected = {-1, 1, 3, 5, 77};
  EXPECT_EQ(expected, in);
  EXPECT_EQ(expected.size(), in.size());

  // Reverse order
  in = {5, 4, 3, 2, 1};
  sort_func(in);
  expected = {1, 2, 3, 4, 5};
  EXPECT_EQ(expected, in);
  EXPECT_EQ(expected.size(), in.size());

  in = {5, 4, 3, 2, 1, 0};
  sort_func(in);
  expected = {0, 1, 2, 3, 4, 5};
  EXPECT_EQ(expected, in);
  EXPECT_EQ(expected.size(), in.size());

  // With duplicate values
  in = {-4, 122, -1000, 222, 45,  66,  97,    1,
        23, 44,  23,    100, 244, 456, -1000, 22};
  sort_func(in);
  expected = {-1000, -1000, -4, 1,   22,  23,  23,  44,
              45,    66,    97, 100, 122, 222, 244, 456};
  EXPECT_EQ(expected, in);
  EXPECT_EQ(expected.size(), in.size());

  // Random large vector
  std::srand(10);  // use a constant seed to make the test repeatable
  in.resize(5000);
  std::generate(in.begin(), in.end(), std::rand);
  expected = in;
  std::sort(expected.begin(), expected.end());
  sort_func(in);
  EXPECT_EQ(expected, in);
  EXPECT_EQ(expected.size(), in.size());
}

TEST(SortTest, SelectionSort) { TestSort(Sort::SelectionSort); }
TEST(SortTest, MergeSort) { TestSort(Sort::MergeSort); }
TEST(SortTest, MergeSortPar) { TestSort(Sort::MergeSortPar); }

TEST(SortTest, BubbleSort) { TestSort(Sort::BubbleSort); }
TEST(SortTest, BubbleSortImproved) { TestSort(Sort::BubbleSortImproved); }
TEST(SortTest, QuickSort) { TestSort(Sort::QuickSort); }
TEST(SortTest, QuickSortPar) { TestSort(Sort::QuickSortPar); }
TEST(SortTest, InsertionSort) { TestSort(Sort::InsertionSort); }

TEST(SortTest, IntroSort) { TestSort(Sort::Introsort); }

