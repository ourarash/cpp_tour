#include <iostream>

void PrintLine(int input) { std::cout << input << std::endl; }
void PrintLine(char input) { std::cout << input << std::endl; }
void PrintLine(float input) { std::cout << input << std::endl; }
void PrintLine(double input) { std::cout << input << std::endl; }

// Prints a string and adds a new line at the end.
void PrintLine(std::string input) { std::cout << input << std::endl; }

int main() {
  std::string text = "Hello world!";
  PrintLine(text);
  PrintLine("Second hellow world");

  return 0;
}