#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "src/lib/dynamic_programming/lpss.h"
#include "src/lib/utility.h"

// Longest Palindromic Subsequence
// Given a string s, find the longest palindromic subsequence's length in s. You
// may assume that the maximum length of s is 1000.

// Example 1:
// Input:

// "bbbab"
// Output:
// 4
// One possible longest palindromic subsequence is "bbbb".
// Example 2:
// Input:

// "cbbd"
// Output:
// 2
// One possible longest palindromic subsequence is "bb".

// Finds LSCS at index i

// Driver function
int main() {
  std::string in = "bbbab";

  LPSS_Problem p(in);
  auto result = p.LPSS(0, in.size());

  std::cout << "result: " << result << std::endl;
  return 0;
}