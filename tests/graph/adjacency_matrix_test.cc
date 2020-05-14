#include <vector>

#include "gtest/gtest.h"
#include "src/lib/graph/adjacency_matrix.h"

TEST(vector_v_vector_pair_e, euler_walkable1) {
  std::vector<std::vector<int>> adjacency = {{0, 1, 1, 0, 0},
                                             {1, 0, 1, 1, 1},
                                             {1, 1, 0, 1, 0},
                                             {0, 1, 1, 0, 1},
                                             {0, 1, 0, 1, 0}};
  Graph g(adjacency);
  EXPECT_EQ(true, g.IsEulerWalkable());
}
