#ifndef LPSS_H
#define LPSS_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

template <class T>
void Print2dVector(std::vector<std::vector<T>> input) {
  std::cout << "{ " << std::endl;
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[0].size(); j++) {
      std::cout << input[i][j];
      if (j < input[0].size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
  }
  std::cout << " }" << std::endl;
}
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
class LPSS_Problem {
 public:
  LPSS_Problem(std::string &s) : _s(s) {
    _memo =
        std::vector<std::vector<int>>(s.size(), std::vector<int>(s.size(), -1));
  }

  int LPSS(int i, int j) {
    if (_s.size() == 0) {
      return 0;
    }
    if (i == j) {
      return 1;
    } else if (_s[i] == _s[j]) {
      if (j == i + 1) {
        return 2;
      } else {
        return LPSS(i + 1, j - 1) + 2;
      }
    } else {
      return std::max(LPSS(i + 1, j), LPSS(i, j - 1));
    }
  }

  int LPSS_Memo(int i, int j) {
    if (_s.size() == 0) {
      return 0;
    }
    if (_memo[i][j] != -1) {
      return _memo[i][j];
    }

    if (i == j) {
      _memo[i][j] = 1;
    } else if (_s[i] == _s[j]) {
      if (j == i + 1) {
        _memo[i][j] = 2;
      } else {
        _memo[i][j] = LPSS_Memo(i + 1, j - 1) + 2;
      }
    } else {
      _memo[i][j] = std::max(LPSS_Memo(i + 1, j), LPSS_Memo(i, j - 1));
    }
    return _memo[i][j];
  }

  int LPSS_Table() {
    std::vector<std::vector<int>> d(_s.size(), std::vector<int>(_s.size()));
    if (_s.size() == 0) {
      return 0;
    }
    // We iterate the length from 0 to _s.size()
    for (int l = 0; l < _s.size(); l++) {
      for (int i = 0; i + l < _s.size(); i++) {
        int j = i + l;
        if (i == j) {
          d[i][j] = 1;
        } else if (_s[i] == _s[j]) {
          d[i][j] = d[i + 1][j - 1] + 2;
        } else {
          d[i][j] = std::max(d[i][j - 1], d[i + 1][j]);
        }
      }
    }
    return d[0][_s.size() - 1];
  }
  std::vector<std::vector<int>> _memo;
  std::string _s;
};

#endif