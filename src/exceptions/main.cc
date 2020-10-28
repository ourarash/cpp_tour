#include <iostream>
#include <string>

int main() {
  try {
    unsigned long size = 1000000000000000;
    int* i = new int[size];
    if (i == nullptr) {
      // deal with error here
    }

    for (int j = 0; j < size; j++) {
      // do something with array i.
    }
    
    std::cout << "Memory allocation succeeded!" << std::endl;
    std::cout << "sizeof(i): " << sizeof(i) << std::endl;
  } catch (std::bad_alloc&) {
    std::cout << "Memory allocation failed :(" << std::endl;

    // Do other things.
  }

  // Avoid catch (...) when possible.
  // catch (...) {
  //   std::cout << "Unknown exception??" << std::endl;
  // }

  return 0;
}

int main2() {
  unsigned long size = 1000000000000000;
  int* i = new int[size];
  if (i == nullptr) {
    // deal with error here
  }

  for (int j = 0; j < size; j++) {
    // do something with array i.
  }
}



void f_a(){

  Person a;
  f_b()
}