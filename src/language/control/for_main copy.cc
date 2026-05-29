#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>

int main() {

  // break and continue
  // This is a very loooooooong comment line. Why would someone write such a
  // long comment line. If this happens you probably want to wrap it around. The
  // shortcut for this is option + z on mac or Alt + z on Windows.

  int your_var = 0;

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
  // Added one more comment here!
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

  std::cout << "------------------------------------------" << std::endl;

  your_var++;
  std::cout << "x: " << your_var << std::endl;

  return 0;
}
