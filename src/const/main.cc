#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>


int main() {
  const int i = 1;
  const int j = i + 1; // Initializing is ok
  i++;                  // Don't change the const!
}