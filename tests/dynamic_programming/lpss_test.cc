#include "src/lib/dynamic_programming/lpss.h"

#include <vector>

#include "gtest/gtest.h"

TEST(LPSS, bbbab) {
  std::string in = "bbbab";
  LPSS_Problem p(in);
  auto result = p.LPSS(0, in.size()-1);
  EXPECT_EQ(4, result);
}

TEST(LPSS, za12bb34a) {
  std::string in = "za12bb34a";
  LPSS_Problem p(in);
  auto result = p.LPSS(0, in.size()-1);
  EXPECT_EQ(4, result);
}

TEST(LPSS, cbbd) {
  std::string in = "cbbd";

  LPSS_Problem p(in);
  auto result = p.LPSS(0, in.size()-1);
  EXPECT_EQ(2, result);
}

TEST(LPSS, Empty) {
  std::string in = "";
  LPSS_Problem p(in);
  auto result = p.LPSS(0, in.size()-1);
  EXPECT_EQ(0, result);
}

TEST(LPSS, Character) {
  std::string in = "Character";
  LPSS_Problem p(in);
  auto result = p.LPSS(0, in.size()-1);
  EXPECT_EQ(3, result);
}

TEST(LPSS, ABBCDABBC) {
  std::string in = "ABBCDABBC";

  LPSS_Problem p(in);
  auto result = p.LPSS(0, in.size()-1);
  EXPECT_EQ(5, result);
}
