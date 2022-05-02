#include <vector>

#include "gtest/gtest.h"
#include "src/lib/graph/distance_matrix.h"

//-----------------------------------------------------------------------------
TEST(Dijkstra, Dijkstra1) {
  std::vector<std::vector<int>> distances{
      {0, 1000, 20, 35},  // 0
      {40, 0, 30, 10},    // 1
      {20, 30, 0, 30},    // 2
      {35, 10, 30, 0},    // 3
  };
  std::vector<std::vector<long>> expected = {
      {0, 45, 20, 35},  // 0
      {40, 0, 30, 10},  // 1
      {20, 30, 0, 30},  // 2
      {35, 10, 30, 0}   // 3
  };
  for (int i = 0; i < expected.size(); i++) {
    DistMatrixGraph g(distances);
    auto actual = g.Dijkstra(i);

    EXPECT_EQ(expected[i], actual);
  }
}

TEST(Dijkstra, Dijkstra2) {
  auto INF = INT_MAX - 1;

  std::vector<std::vector<int>> distances = {
      {0, 4, 2, INF, INF, INF},        // 0
      {INF, 0, 5, 10, INF, INF},       // 1
      {INF, INF, 0, INF, 3, INF},      // 2
      {INF, INF, INF, 0, INF, 11},     // 3
      {INF, INF, INF, 4, 0, INF},      // 4
      {INF, INF, INF, INF, INF, INF},  // 5
  };
  std::vector<std::vector<long>> expected = {
      {0, 4, 2, 9, 5, 20},            // 0
      {INF, 0, 5, 10, 8, 21},         // 1
      {INF, INF, 0, 7, 3, 18},        // 2
      {INF, INF, INF, 0, INF, 11},    // 3
      {INF, INF, INF, 4, 0, 15},      // 4
      {INF, INF, INF, INF, INF, INF}  // 5
  };
  for (int i = 0; i < expected.size(); i++) {
    DistMatrixGraph g(distances);
    auto actual = g.Dijkstra(i);

    EXPECT_EQ(expected[i], actual);
  }
}

TEST(Dijkstra, Dijkstra3) {
  auto INF = INT_MAX - 1;

  std::vector<std::vector<int>> distances = {
      {0, 4, INF, INF, INF, INF, INF, 8, INF},   // 0
      {4, 0, 8, INF, INF, INF, INF, 11, INF},    // 1
      {INF, 8, 0, 7, INF, 4, INF, INF, 2},       // 2
      {INF, INF, 7, 0, 9, 14, INF, INF, INF},    // 3
      {INF, INF, INF, 9, 0, 10, INF, INF, INF},  // 4
      {INF, INF, 4, 14, 10, 0, 2, INF, INF},     // 5
      {INF, INF, INF, INF, INF, 2, 0, 1, 6},     // 6
      {8, 11, INF, INF, INF, INF, 1, 0, 7},      // 7
      {INF, INF, 2, INF, INF, INF, 6, 7, 0}      // 8
  };
  std::vector<std::vector<long>> expected = {
      {0, 4, 12, 19, 21, 11, 9, 8, 14},    // 0
      {4, 0, 8, 15, 22, 12, 12, 11, 10},   // 1
      {12, 8, 0, 7, 14, 4, 6, 7, 2},       // 2
      {19, 15, 7, 0, 9, 11, 13, 14, 9},    // 3
      {21, 22, 14, 9, 0, 10, 12, 13, 16},  // 4
      {11, 12, 4, 11, 10, 0, 2, 3, 6},     // 5
      {9, 12, 6, 13, 12, 2, 0, 1, 6},      // 6
      {8, 11, 7, 14, 13, 3, 1, 0, 7},      // 7
      {14, 10, 2, 9, 16, 6, 6, 7, 0}       // 8
  };
  for (int i = 0; i < expected.size(); i++) {
    DistMatrixGraph g(distances);
    auto actual = g.Dijkstra(i);

    EXPECT_EQ(expected[i], actual);
  }
}
