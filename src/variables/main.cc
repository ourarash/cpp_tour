#include <iostream>
#include <string>

// Prints a string and adds a new line at the end.
void PrintLine(std::string text) { std::cout << text << std::endl; }

int main() {

  std::string hello = "Hello";
  std::string world = " world";
  int year = 2020;

  std::string hello_world = hello + world + " " + std::to_string(year);

  PrintLine(hello_world);
  return 0;
}