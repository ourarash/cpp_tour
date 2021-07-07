#include "src/lib/segment_tree/segment_tree.h"

#include <vector>

#include "gtest/gtest.h"
#include "src/lib/utility.h"

//-----------------------------------------------------------------------------
// Building
//-----------------------------------------------------------------------------
TEST(SegmentTreeTest, CanBuildTreeOfTwoElements) {
  std::vector<int> in{1, 3};

  SegmentTree<int> t(in);
  t.build(in, /*index=*/0, /*l=*/0, /*r=*/in.size() - 1);

  std::vector<int> actual, expected = {4, 1, 3, 0, 0, 0, 0, 0};

  std::transform(t.elements.begin(), t.elements.end(),
                 std::back_inserter(actual), [](auto &n) { return n.value; });

  EXPECT_EQ(actual, expected);
}

TEST(SegmentTreeTest, CanBuildTreeOfFourElements) {
  std::vector<int> in{1, 3, -2, 8};
  SegmentTree<int> t(in);
  t.build(in, /*index=*/0, /*l=*/0, /*r=*/in.size() - 1);

  std::vector<int> actual,
      expected = {10, 4, 6, 1, 3, -2, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  std::transform(t.elements.begin(), t.elements.end(),
                 std::back_inserter(actual), [](auto &n) { return n.value; });

  EXPECT_EQ(actual, expected);
}

TEST(SegmentTreeTest, CanBuildTreeOfFiveElements) {
  std::vector<int> in{1, 3, -2, 8, -7};
  SegmentTree<int> t(in);
  t.build(in, /*index=*/0, /*l=*/0, /*r=*/in.size() - 1);

  std::vector<int> actual,
      expected = {3, 2, 1, 4, -2, 8, -7, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  std::transform(t.elements.begin(), t.elements.end(),
                 std::back_inserter(actual), [](auto &n) { return n.value; });

  EXPECT_EQ(actual, expected);
}

TEST(SegmentTreeTest, CanBuildTreeOfSixteenElements) {
  std::vector<int> in(16);
  int i = 0;
  std::generate(in.begin(), in.end(), [&i]() { return i++; });

  SegmentTree<int> t(in);
  t.build(in, /*index=*/0, /*l=*/0, /*r=*/in.size() - 1);

  std::vector<int> actual,
      expected = {120, 28, 92, 6, 22, 38, 54, 1, 5, 9,  13, 17, 21, 25, 29, 0,
                  1,   2,  3,  4, 5,  6,  7,  8, 9, 10, 11, 12, 13, 14, 15, 0,
                  0,   0,  0,  0, 0,  0,  0,  0, 0, 0,  0,  0,  0,  0,  0,  0,
                  0,   0,  0,  0, 0,  0,  0,  0, 0, 0,  0,  0,  0,  0,  0,  0};

  std::transform(t.elements.begin(), t.elements.end(),
                 std::back_inserter(actual), [](auto &n) { return n.value; });

  EXPECT_EQ(actual, expected);
}
//-----------------------------------------------------------------------------
TEST(SegmentTreeTest, CanQueryTreeOfFiveElements1) {
  std::vector<int> in{1, 3, -2, 8, -7};
  SegmentTree<int> t(in);
  t.build(in, /*index=*/0, /*l=*/0, /*r=*/in.size() - 1);
  int expected = -1;
  auto actual =
      t.query(/*index=*/0, /*tl=*/0, /*tr=*/in.size() - 1, /*l=*/2, /*r=*/4);

  EXPECT_EQ(actual, expected);
}

TEST(SegmentTreeTest, CanQueryTreeOfFiveElements2) {
  std::vector<int> in{1, 3, -2, 8, -7};
  SegmentTree<int> t(in);
  t.build(in, /*index=*/0, /*l=*/0, /*r=*/in.size() - 1);
  int expected = 10;
  auto actual =
      t.query(/*index=*/0, /*tl=*/0, /*tr=*/in.size() - 1, /*l=*/0, /*r=*/3);

  EXPECT_EQ(actual, expected);
}

TEST(SegmentTreeTest, CanQueryTreeOfFiveElements3) {
  std::vector<int> in{1, 3, -2, 8, -7};
  SegmentTree<int> t(in);
  t.build(in, /*index=*/0, /*l=*/0, /*r=*/in.size() - 1);
  int expected = 9;
  auto actual =
      t.query(/*index=*/0, /*tl=*/0, /*tr=*/in.size() - 1, /*l=*/1, /*r=*/3);

  EXPECT_EQ(actual, expected);
}
//-----------------------------------------------------------------------------
// Building Max
//-----------------------------------------------------------------------------
TEST(SegmentTreeTest, CanBuildTreeOfTwoElementsMax) {
  std::vector<int> in{1, 3};

  SegmentTree<int> t(in);
  t.build(in, /*index=*/0, /*l=*/0, /*r=*/in.size() - 1, Max<int>);

  std::vector<int> actual, expected = {3, 1, 3, 0, 0, 0, 0, 0};

  std::transform(t.elements.begin(), t.elements.end(),
                 std::back_inserter(actual), [](auto &n) { return n.value; });

  EXPECT_EQ(actual, expected);
}

TEST(SegmentTreeTest, CanBuildTreeOfFourElementsMax) {
  std::vector<int> in{1, 3, -2, 8};
  SegmentTree<int> t(in);
  t.build(in, /*index=*/0, /*l=*/0, /*r=*/in.size() - 1, Max<int>);

  std::vector<int> actual,
      expected = {8, 3, 8, 1, 3, -2, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  std::transform(t.elements.begin(), t.elements.end(),
                 std::back_inserter(actual), [](auto &n) { return n.value; });

  EXPECT_EQ(actual, expected);
}