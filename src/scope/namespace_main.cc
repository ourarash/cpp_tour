#include <iostream>
#include <string>
#include <vector>

// namespaces
#include <iostream>


using namespace std;  // Generall, don't do this.

// Global namespace
int x = 0;
void PrintSomething() { std::cout << "Printing example 0." << std::endl; }

namespace ns1 {
int x = 1;
void PrintSomething() { std::cout << "Printing example 1." << std::endl; }

}  // namespace ns1

namespace ns2 {
int x = 2;
void PrintSomething() { std::cout << "Printing example 2." << std::endl; }

}  // namespace ns2



int main() {
  std::cout << "ns1::x: " << ns1::x << std::endl;
  std::cout << "ns2::x: " << ns2::x << std::endl;
  std::cout << "::x: " << ::x << std::endl;

  // ns1::yStruct.x = 10;
  // ns2::yStruct.x = 11;

  // PrintSomething();
  ns2::PrintSomething();
  ::PrintSomething();

  return 0;
}