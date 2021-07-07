#include "src/lib/consonant_vowel_imbalance/consonant_vowel_imbalance.h"

#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "src/lib/utility.h"

//-----------------------------------------------------------------------------
// Building
//-----------------------------------------------------------------------------
TEST(ConsonantVowelImbalance, sInput) {
  ConsonantAndVowels s;
  std::string in = "s";
  auto actual = s.CVImbalance(in, 0, in.size() - 1);
  auto expected = 1;
  EXPECT_EQ(actual, expected);
}

TEST(ConsonantVowelImbalance, amInput) {
  ConsonantAndVowels s;
  std::string in = "am";
  auto actual = s.CVImbalance(in, 0, in.size() - 1);
  auto expected = 2;
  EXPECT_EQ(actual, expected);
}

TEST(ConsonantVowelImbalance, samInput) {
  ConsonantAndVowels s;
  std::string in = "sam";
  auto actual = s.CVImbalance(in, 0, in.size() - 1);
  auto expected = 4;
  EXPECT_EQ(actual, expected);
}

TEST(ConsonantVowelImbalance, pInput) {
  ConsonantAndVowels s;
  std::string in = "p";
  auto actual = s.CVImbalance(in, 0, in.size() - 1);
  auto expected = 1;
  EXPECT_EQ(actual, expected);
}

TEST(ConsonantVowelImbalance, leInput) {
  ConsonantAndVowels s;
  std::string in = "le";
  auto actual = s.CVImbalance(in, 0, in.size() - 1);
  auto expected = 2;
  EXPECT_EQ(actual, expected);
}

TEST(ConsonantVowelImbalance, pleInput) {
  ConsonantAndVowels s;
  std::string in = "ple";
  auto actual = s.CVImbalance(in, 0, in.size() - 1);
  auto expected = 4;
  EXPECT_EQ(actual, expected);
}

TEST(ConsonantVowelImbalance, sampleInput) {
  ConsonantAndVowels s;
  std::string in = "sample";
  auto actual = s.CVImbalance(in, 0, in.size() - 1);
  auto expected = 10;
  EXPECT_EQ(actual, expected);
}

TEST(ConsonantVowelImbalance, sample10Input) {
  ConsonantAndVowels s;
  std::string in =
      "samplesamplesamplesamplesamplesamplesamplesamplesamplesample";
  auto actual = s.CVImbalance(in, 0, in.size() - 1);
  auto expected = 176;
  EXPECT_EQ(actual, expected);
}
