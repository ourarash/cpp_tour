#include "src/lib/search/search.h"

#include <functional>
#include <vector>

#include "gtest/gtest.h"

template <class T>
void TestSearch(T search_func) {
  std::vector<int> in;
  int n;
  int expected;
  int actual;

  // Check empty
  in = {};
  n = 1;
  actual = search_func(in, n);

  expected = -1;
  EXPECT_EQ(expected, actual);

  // Check empty
  in = {};
  n = 1;
  actual = search_func(in, n);

  expected = -1;
  EXPECT_EQ(expected, actual);

  // Array of 1 element
  in = {3};
  n = 3;
  actual = search_func(in, n);
  expected = 0;
  EXPECT_EQ(expected, actual);

  // Array of 1 element not found
  in = {3};
  n = 1;
  actual = search_func(in, n);
  expected = -1;
  EXPECT_EQ(expected, actual);

  // Small vector
  in = {-1, 1, 2, 2, 3, 4, 10};
  n = 3;
  actual = search_func(in, n);
  expected = 4;
  EXPECT_EQ(expected, actual);

  // Small vector not found
  in = {-1, 1, 2, 2, 3, 4, 10};
  n = 100;
  actual = search_func(in, n);
  expected = -1;
  EXPECT_EQ(expected, actual);

  // All equal
  in = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
  n = 10;
  actual = search_func(in, n);
  expected = 5;
  EXPECT_EQ(expected, actual);
}

TEST(TestSearch, BinarySearchRecursive) {
  TestSearch(Search::BinarySearchRecursive);
}

TEST(TestSearch, BinarySearchIterative) {
  TestSearch(Search::BinarySearchIterative);
}
