#include "src/lib/dynamic_programming/lpss.h"

#include <vector>

#include "gtest/gtest.h"

TEST(LPSS_Memo, bbbab) {
  std::string in = "bbbab";
  LPSS_Problem p(in);
  auto result = p.LPSS_Memo(0, in.size()-1);
  EXPECT_EQ(4, result);
}

TEST(LPSS_Memo, cbbd) {
  std::string in = "cbbd";

  LPSS_Problem p(in);
  auto result = p.LPSS_Memo(0, in.size()-1);
  EXPECT_EQ(2, result);
}

TEST(LPSS_Memo, Empty) {
  std::string in = "";
  LPSS_Problem p(in);
  auto result = p.LPSS_Memo(0, in.size()-1);
  EXPECT_EQ(0, result);
}

TEST(LPSS_Memo, Character) {
  std::string in = "Character";
  LPSS_Problem p(in);
  auto result = p.LPSS_Memo(0, in.size()-1);
  EXPECT_EQ(3, result);
}

TEST(LPSS_Memo, ABBCDABBC) {
  std::string in = "ABBCDABBC";

  LPSS_Problem p(in);
  auto result = p.LPSS_Memo(0, in.size()-1);
  EXPECT_EQ(5, result);
}
