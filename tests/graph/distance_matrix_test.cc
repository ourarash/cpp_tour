#include "src/lib/graph/distance_matrix.h"

#include <vector>

#include "gtest/gtest.h"

TEST(TSP_Test, TSP) {
  std::vector<std::vector<int>> distances;

  {
    distances = {
        {0, 40, 20, 35},
        {40, 0, 30, 10},
        {20, 30, 0, 30},
        {35, 10, 30, 0},
    };
    DistMatrixGraph g(distances);
    EXPECT_EQ(95, g.TSP1(0));
    EXPECT_EQ(95, g.TSP2(0));
    EXPECT_EQ(95, g.TSP3(0));
    EXPECT_EQ(95, g.TSP4(0));
    EXPECT_EQ(95, g.TSP5(0));
  }

  {
    distances = {
        {0, 40, 20, 35},
        {40, 0, 30, 100},
        {20, 30, 0, 30},
        {35, 100, 30, 0},
    };
    DistMatrixGraph g(distances);
    EXPECT_EQ(135, g.TSP1(0));
    EXPECT_EQ(135, g.TSP2(0));
    EXPECT_EQ(135, g.TSP3(0));
    EXPECT_EQ(135, g.TSP4(0));
    EXPECT_EQ(135, g.TSP5(0));
  }

  {
    distances = {
        {0, 40, 20, 35},
        {40, 0, 30, 100},
        {20, 30, 0, 30},
        {35, 100, 30, 0},
    };
    DistMatrixGraph g(distances);
    EXPECT_EQ(135, g.TSP1(0));
    EXPECT_EQ(135, g.TSP2(0));
    EXPECT_EQ(135, g.TSP3(0));
    EXPECT_EQ(135, g.TSP4(0));
    EXPECT_EQ(135, g.TSP5(0));
  }

  {
    distances = {
        {0, 40},
        {40, 0},

    };
    DistMatrixGraph g(distances);
    EXPECT_EQ(80, g.TSP1(0));
    EXPECT_EQ(80, g.TSP2(0));
    EXPECT_EQ(80, g.TSP3(0));
    EXPECT_EQ(80, g.TSP4(0));
    EXPECT_EQ(80, g.TSP5(0));
  }

  {
    distances = {
        {0, 20, 42, 35},
        {20, 0, 30, 34},
        {42, 30, 0, 12},
        {35, 34, 12, 0},

    };
    DistMatrixGraph g(distances);
    EXPECT_EQ(97, g.TSP1(0));
    EXPECT_EQ(97, g.TSP2(0));
    EXPECT_EQ(97, g.TSP3(0));
    EXPECT_EQ(97, g.TSP4(0));
    EXPECT_EQ(97, g.TSP5(0));
  }

  {
    distances = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0},

    };
    DistMatrixGraph g(distances);
    EXPECT_EQ(80, g.TSP1(0));
    EXPECT_EQ(80, g.TSP2(0));
    EXPECT_EQ(80, g.TSP3(0));
    EXPECT_EQ(80, g.TSP4(0));
    EXPECT_EQ(80, g.TSP5(0));
  }

  {
    distances = {
        {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 16, 0, 12},
        {8, 8, 9, 0},
    };
    DistMatrixGraph g(distances);
    EXPECT_EQ(35, g.TSP1(0));
    EXPECT_EQ(35, g.TSP2(0));
    EXPECT_EQ(35, g.TSP3(0));
    EXPECT_EQ(35, g.TSP4(0));
    EXPECT_EQ(35, g.TSP5(0));
  }
  {
    distances = {
        {0, 10, 15},
        {5, 0, 9},
        {6, 16, 0},

    };
    DistMatrixGraph g(distances);
    EXPECT_EQ(25, g.TSP1(0));
    EXPECT_EQ(25, g.TSP2(0));
    EXPECT_EQ(25, g.TSP3(0));
    EXPECT_EQ(25, g.TSP4(0));
    EXPECT_EQ(25, g.TSP5(0));
  }
}
//-----------------------------------------------------
// Tests FloydWarshallRecursive and FloydWarshallRecursiveMemo
TEST(FloydWarshallRecursive, FloydWarshallRecursive1) {
  std::vector<std::vector<int>> distances;

  {
    distances = {
        {0, 1000, 20, 35},  // 0
        {40, 0, 30, 10},    // 1
        {20, 30, 0, 30},    // 2
        {35, 10, 30, 0},    // 3
    };
    {
      DistMatrixGraph g(distances);
      std::vector<std::vector<long>> actual = g.FloydWarshallRecursive();
      std::vector<std::vector<long>> expected = {
          {0, 45, 20, 35},  // 0
          {40, 0, 30, 10},  // 1
          {20, 30, 0, 30},  // 2
          {35, 10, 30, 0}   // 3
      };
      EXPECT_EQ(expected, actual);
    }
    {
      DistMatrixGraph g(distances);
      std::vector<std::vector<long>> actual = g.FloydWarshallRecursiveMemo();
      std::vector<std::vector<long>> expected = {
          {0, 45, 20, 35},  // 0
          {40, 0, 30, 10},  // 1
          {20, 30, 0, 30},  // 2
          {35, 10, 30, 0}   // 3
      };
      EXPECT_EQ(expected, actual);
    }
  }
}

// Tests FloydWarshallRecursive and FloydWarshallRecursiveMemo
TEST(FloydWarshallRecursive, FloydWarshallRecursive2) {
  std::vector<std::vector<int>> distances;
  auto INF = INT_MAX;
  {
    distances = {
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

    DistMatrixGraph g(distances);
    std::vector<std::vector<long>> actual_no_memo = g.FloydWarshallRecursive();
    std::vector<std::vector<long>> actual_memo = g.FloydWarshallRecursiveMemo();

    EXPECT_EQ(expected, actual_no_memo);
    EXPECT_EQ(expected, actual_memo);
  }
}
// Tests FloydWarshallRecursive and FloydWarshallRecursiveMemo
TEST(FloydWarshallRecursive, FloydWarshallRecursive3) {
  std::vector<std::vector<int>> distances;
  auto INF = INT_MAX;
  {
    distances = {
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

    DistMatrixGraph g(distances);

    auto start_time_no_memo = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<long>> actual_no_memo = g.FloydWarshallRecursive();
    auto end_time_no_memo = std::chrono::high_resolution_clock::now();
    auto duration_no_memo =
        std::chrono::duration_cast<std::chrono::milliseconds>(
            end_time_no_memo - start_time_no_memo);

    auto start_time_memo = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<long>> actual_memo = g.FloydWarshallRecursiveMemo();
    auto end_time_memo = std::chrono::high_resolution_clock::now();
    auto duration_memo = std::chrono::duration_cast<std::chrono::milliseconds>(
        end_time_memo - start_time_memo);

    EXPECT_EQ(expected, actual_no_memo);
    EXPECT_EQ(expected, actual_memo);
    std::cout << "duration_no_memo: " << duration_no_memo.count() << std::endl;
    std::cout << "duration_memo: " << duration_memo.count() << std::endl;
    EXPECT_LE(duration_memo.count(), duration_no_memo.count());
  }
}