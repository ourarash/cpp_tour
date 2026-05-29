#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

void handle_eptr(std::exception_ptr eptr)  // passing by value is ok
{
  try {
    if (eptr) {
      std::rethrow_exception(eptr);
    }
  } catch (const std::exception& e) {
    std::cout << "Caught exception \"" << e.what() << "\"\n";
  }
}

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

  {
    std::exception_ptr eptr;
    try {
      std::string().at(1);  // this generates an std::out_of_range
    } catch (...) {
      eptr = std::current_exception();  // capture
    }
    handle_eptr(eptr);
  }  //

  {
    std::exception_ptr eptr;
    try {
      throw(1);  // this generates an std::out_of_range
    } catch (...) {
      eptr = std::current_exception();  // capture
    }
    handle_eptr(eptr);
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
