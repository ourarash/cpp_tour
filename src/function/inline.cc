#include <iostream>
inline int f(int a, int b) {
  return a + b;
}  // assume compilers are willing to inline calls to f
int main(int argc, char const *argv[]) {
  int (*pf)(int, int) = f;  // pf points to f
  int x;
  std::cin >> x;
  int a = f(x, 100);   // this call will be inlined, because it's a "normal" call
  int b = pf(x, 120);  // this call probably won't be, because it's through
  std::cout << "pf: " << pf << std::endl;
  // a function pointer
  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;
  return 0;
}
