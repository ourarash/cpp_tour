#include "src/lib/graph/adjacency_vector_of_set.h"

#include <vector>

#include "gtest/gtest.h"

TEST(vector_v_vector_pair_e, euler_walkable1) {
  Graph g({Vertex(0, {1, 2}), Vertex(1, {0, 2, 3, 4}), Vertex(2, {0, 1, 3}),
           Vertex(3, {1, 2, 4})});
  EXPECT_EQ(true, g.IsEulerWalkable());
}
TEST(vector_v_vector_pair_e, euler_walkable2) {
  Graph g({Vertex(0, {1, 2, 3}), Vertex(1, {0, 2, 3}), Vertex(2, {0, 1, 3}),
           Vertex(3, {0, 1, 2})});
  EXPECT_EQ(false, g.IsEulerWalkable());
}
