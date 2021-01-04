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
