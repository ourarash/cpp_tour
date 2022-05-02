#include <iostream>
#include <string>
#include <vector>

#include "src/lib/utility.h"

int main() {
  std::string s = "Hello world";
  for (auto c : s) {
    std::cout << "c: " << c << std::endl;
    s.push_back('!');
  }

  int i, j;

  int *p;

  p = &i;

  p = &j;

  std::cout << *p << std::endl;

  std::vector<int> my_vector;
  int i = 0;

  for (; i < 10;) {
  }
  
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
  i = 0;
  while (i < 10) {
    if (i == 2) {
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