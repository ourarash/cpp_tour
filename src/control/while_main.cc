#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>

int main() {

  std::vector<int> my_vector;
  int i = 0;

  while (i < 10) {
    my_vector.push_back(i++);
  }
  PrintVector(my_vector);

  // Do while
  my_vector.clear();
  do {
    my_vector.push_back(i);
  } while (i < 10);
  PrintVector(my_vector);

  // Break and continue
  my_vector.clear();
  i = 0 ;
  while (i < 10) {
    if (i == 2) {
      i++;
      continue;
    }
    if (i == 5) {
      break;
    }
    my_vector.push_back(i++);
  }
  PrintVector(my_vector);

  return 0;
}