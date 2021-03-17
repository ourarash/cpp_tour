#include <iostream>
template <unsigned int n>
struct factorial {
  enum { value = n * factorial<n - 1>::value };
};

template <>
struct factorial<0> {
  enum { value = 1 };
};

int main() { return 0; }
