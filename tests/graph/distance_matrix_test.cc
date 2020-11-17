#include "src/lib/graph/distance_matrix.h"

#include <vector>

#include "gtest/gtest.h"

TEST(TSP_Test, TSP1) {
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
  }
}
