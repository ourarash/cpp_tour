#include "src/lib/graph/adjacency_vector_of_set.h"

#include <vector>

#include "gtest/gtest.h"

TEST(vector_v_vector_pair_e, euler_walkable1) {
  Graph g({Vertex(1, {2, 3}), Vertex(2, {1, 3, 4, 5}), Vertex(3, {1, 2, 4}),
           Vertex(4, {2, 4, 4})});
  EXPECT_EQ(true, g.IsEulerWalkable());
}

// TEST(vector_v_vector_pair_e, euler_walkable2) {
//   std::vector<int> v = {0, 1, 2, 3};
//   std::vector<std::pair<int, int>> e = {{0, 1}, {0, 2}, {0, 3},
//                                         {1, 2}, {1, 3}, {2, 3}};
//   Graph g(v, e);
//   EXPECT_EQ(false, g.IsEulerWalkable());
// }

// TEST(vector_v_vector_pair_e, euler_walkable3) {
//   std::vector<int> v = {0, 1, 2, 3};
//   std::vector<std::pair<int, int>> e = {{1, 3}, {1, 3}, {3, 0}, {3, 0},
//                                         {0, 2}, {2, 1}, {2, 3}};
//   Graph g(v, e);
//   EXPECT_EQ(false, g.IsEulerWalkable());
// }
