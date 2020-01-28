#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>
// namespaces
#include <iostream>
int x = 0;
void PrintSomething() { std::cout << "Printing example 0." << std::endl; }

namespace ns1 {
int x = 1;
void PrintSomething() { std::cout << "Printing example 1." << std::endl; }

} // namespace ns1

namespace ns1 {
int x = 2;
void PrintSomething2() { std::cout << "Printing example 2." << std::endl; }
} // namespace ns1

int main() {
  std::cout << "ns1::x: " << ns1::x << std::endl;
  std::cout << "ns2::x: " << ns2::x << std::endl;
  std::cout << "::x: " << ::x << std::endl;

  ns1::PrintSomething();
  ns1::PrintSomething2();
  ::PrintSomething();
  return 0;
}