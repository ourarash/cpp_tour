#include <vector>

#include "gtest/gtest.h"
#include "src/lib/questions/social_distance.h"

TEST(VectorUnion, ShouldPrintMinValue) {
  QSocialDistance s;
  std::vector<std::vector<char>> grid = {
      {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
      {'-', '-', '-', '-', '-', '-', '-', 'M', '-', '-'},
      {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
      {'-', '-', '-', '-', '-', '-', '-', '-', 'C', '-'},
      {'-', 'C', '-', '-', '-', '-', '-', '-', '-', '-'},
      {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
      {'-', '-', '-', '-', 'C', '-', '-', '-', '-', '-'},
      {'-', '-', '-', '-', '-', '-', '-', 'C', '-', '-'},
      {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
      {'-', 'C', '-', '-', 'X', '-', '-', '-', '-', '-'},
  };

  auto distances = s.FindDistances(grid);
  Print2dVector(distances);

  auto  is = s.IsMinimumMaximumDistanceK(grid, 2, 9, 4, )

  EXPECT_EQ(true, false);
}