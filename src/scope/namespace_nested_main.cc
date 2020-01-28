#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>
// namespaces
#include <iostream>
int x = 0;
void PrintSomething() { std::cout << "Printing example 0." << std::endl; }

namespace ns1 {
  void PrintSomething1() { std::cout << "Printing example 2." << std::endl; }

  namespace ns2 {
  int x = 1;
  void PrintSomething1() { std::cout << "Printing example 1." << std::endl; }
} // namespace ns2
}; // namespace ns1

int main() {

  ns1::PrintSomething1();
  ns1::ns2::PrintSomething1();
  ::PrintSomething();
  return 0;
}