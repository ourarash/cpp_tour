#include <iostream>
#include <string>

// Prints a string and adds a new line at the end.
void PrintLine(std::string text) { std::cout << text << std::endl; }

int MakeDouble(int x) { return x * 2; }

int main() {
  std::string hello = "Hello";
  std::string world = " world";

  int y = MakeDouble(6);
  auto z = MakeDouble(6);

  int i = 10;
  int j = i;

  i++;

  std::cout << "j: " << j << std::endl;
  std::cout << "i: " << i << std::endl;

  // int year = 2020;  // Variable definition and Initialization

  int year;     // Variable definition
  year = 2022;  // Assignment

  std::string hello_world = hello + world + ';' + std::to_string(year);

  char x = 'A';  // single byte, usually from ASCII table

  std::string y = "this is a string";

  std::cout << "x is: " << x << std::endl;

  PrintLine(hello_world);
  return 0;
}