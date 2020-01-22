#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>

int main() {

  std::vector<int> my_vector;
  for (int i = 0; i < 10; i++) {
    my_vector.push_back(i);
  }
  PrintVector(my_vector);

  // i, j have to be of the same type!
  my_vector.clear();
  {
    for (int i = 0, j = 0; i < 10; i++, j += 2) {
      my_vector.push_back(i + j);
    }

    PrintVector(my_vector);
  }

  // i, j with different types
  my_vector.clear();
  {
    int i = 0;
    unsigned int j = 0;
    for (; i < 10;) {
      my_vector.push_back(i + j);
      i++;
      j += 2;
    }

    PrintVector(my_vector);
  }

  // break and continue
  my_vector.clear();
  for (int i = 0; i < 10; i++) {
    if (i == 2) {
      continue;
    }
    if (i > 5) {
      break;
    }
    my_vector.push_back(i);
  }
  PrintVector(my_vector);

  return 0;
}