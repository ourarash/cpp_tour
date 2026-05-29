// Effective C++, Item 48
#include <iostream>
template <unsigned n>  // general case: the value of
struct Factorial {     // Factorial<n> is n times the value
  // of Factorial<n-1>
  enum { value = n * Factorial<n - 1>::value };
};
template <>            // special case: the value of
struct Factorial<0> {  // Factorial<0> is 1
  enum { value = 1 };
};
int main(int argc, char const *argv[]) {
  auto i = Factorial<10>::value;

  std::cout << "i: " << i << std::endl;
  return 0;
}
