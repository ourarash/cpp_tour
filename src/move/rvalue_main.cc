#include <iostream>
#include <vector>

int main() {
  // Invalid rvalue operations
  {
    int a = 1;
    int b + 1 = a;  // Invalid!
  }

  // Ternary operation
  {
    int a = 0, b = 0;
    bool condition = true;
    condition ? a : b = 1;
  }

  // Valid lvalue pointer operations
  {
    int a = 1;

    int *ptr_a_0 = &a;      // valid, because a is an lvalue
    int *ptr_a_1 = &(++a);  // Valid, because ++a is an lvalue
  }

  // Invalid rvalue pointer operations
  {
    int a = 1;
    int *ptr_a_2 = &(a++);    // Valid, because a++ is an rvalue
    int *ptr_a_3 = &(a + 1);  // Invalid, because (a + 1) is not an lvalue
  }

  // Valid reference
  {
    int a = 1;
    int &ref_a_0 = a;  // valid
  }

  // Invalid reference
  {
    int a = 1;
    int &ref_a_0 = (a + 1);  // invalid
  }

  return 0;
}