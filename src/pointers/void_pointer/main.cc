// This file shows applications of malloc/calloc and also void pointer
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

int main() {
  int a = 10;

  void* ptr = &a;  // pointer holds the address of the "a" variable
  std::cout << (*(int*)ptr) << std::endl;  // dereference the void pointer

  int n = 4;
  void* malloc_memory = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    int e = (*((int*)(malloc_memory) + i));
    std::cout << "e: " << e << std::endl;
    (*((int*)(malloc_memory) + i)) = i;

    e = (*((int*)(malloc_memory) + i));
    std::cout << "e: " << e << std::endl;
  }

  // How does free know how many bytes it should deallocate?
  free(malloc_memory);

  std::cout << "---------------------------------------------------------------"
            << std::endl;
  // Allocates memory for an array of num objects of size and initializes all
  // bytes in the allocated storage to zero.
  void* calloc_memory = calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) {
    int e = (*((int*)(calloc_memory) + i));
    std::cout << "e: " << e << std::endl;
  }

  free(calloc_memory);

  // void pointer
  {
    int a = 12;
    void* void_pointer = &a;  // pointer holds the address of the "A" variable
    std::cout << "void_pointer: " << void_pointer << std::endl;

    // Using void_pointer directly gives us compile error
    // std::cout << "*void_pointer: " << *void_pointer << std::endl;

    // Convert it into int* using c cast
    std::cout << "*((int*) void_pointer): " << *((int*)void_pointer)
              << std::endl;
    // Convert it into int* using static_cast
    std::cout << "*(static_cast<int*>(void_pointer)): "
              << *(static_cast<int*>(void_pointer)) << std::endl;
  }

  return 0;
}