// forward example
#include <iostream>  // std::cout
#include <utility>   // std::forward

// function with lvalue and rvalue reference overloads:
void overloaded(const int& x) { std::cout << "[lvalue]"; }
void overloaded(int&& x) { std::cout << "[rvalue]"; }

// function template taking rvalue reference to deduced type:
template <class T>
void fn(T&& x) {
  overloaded(x);                   // always an lvalue
  overloaded(std::forward<T>(x));  // rvalue if argument is rvalue
  
  // std::forward<T>(x):
  //   If arg is an lvalue reference, the function returns arg with its type
  //   unchanged.
  // Otherwise, the function returns an rvalue reference (T&&) that refers to
  // arg that can be used to pass an rvalue.
}

int main() {
  int a;

  std::cout << "calling fn with lvalue: ";
  fn(a);
  std::cout << '\n';

  std::cout << "calling fn with rvalue: ";
  fn(0);
  std::cout << '\n';

  return 0;
}