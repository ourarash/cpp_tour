#include "src/lib/utility.h"
#include <iostream>
#include <string>

struct Person {
  std::string first_name;
  std::string last_name;
  int age;
};

int main() {

  // Index out of bound
  int arr[4];

  for (int i = 0; i < 10; i++) {
    arr[i] = 0;
  }

  return 0;
}