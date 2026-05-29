#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "src/lib/utility.h"

int f(int input) {
  int result;
  result = VeryComplexFunction(input);

  return result;
}

// memo map works like a cache
std::map<int, int> memo;
int f(int input) {
  // If it exists in the cache return the value immediately
  if (memo.count(input) > 0) {
    return memo[input];
  }

  memo[input] = VeryComplexFunction(input);

  return memo[input];
}


