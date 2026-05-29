#include <iostream>
struct X {
  int a;
  char b;
  int c;
};
int main(void) { std::cout << sizeof(X) << std::endl; }