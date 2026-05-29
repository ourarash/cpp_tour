#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>
// namespaces
#include <iostream>
int x = 0;

namespace  {
  void PrintSomething() { std::cout << "Printing example 2." << std::endl; }

}; // namespace ns1

int main() {

  PrintSomething();
  return 0;
}