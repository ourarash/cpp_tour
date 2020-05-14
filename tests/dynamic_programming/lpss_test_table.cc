#include "src/lib/dynamic_programming/lpss.h"

#include <vector>

#include "gtest/gtest.h"

TEST(LPSS_Table, bbbab) {
  std::string in = "bbbab";
  LPSS_Problem p(in);
  auto result = p.LPSS_Table();
  EXPECT_EQ(4, result);
}

TEST(LPSS_Table, cbbd) {
  std::string in = "cbbd";

  LPSS_Problem p(in);
  auto result = p.LPSS_Table();
  EXPECT_EQ(2, result);
}

TEST(LPSS_Table, Empty) {
  std::string in = "";
  LPSS_Problem p(in);
  auto result = p.LPSS_Table();
  EXPECT_EQ(0, result);
}

TEST(LPSS_Table, Character) {
  std::string in = "Character";
  LPSS_Problem p(in);
  auto result = p.LPSS_Table();
  EXPECT_EQ(3, result);
}

TEST(LPSS_Table, ABBCDABBC) {
  std::string in = "ABBCDABBC";

  LPSS_Problem p(in);
  auto result = p.LPSS_Table();
  EXPECT_EQ(5, result);
}
