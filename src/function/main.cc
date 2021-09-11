#include <iostream>

void PrintLine(int input) { std::cout << input << std::endl; }
void PrintLine(char input) { std::cout << input << std::endl; }
void PrintLine(float input) { std::cout << input << std::endl; }
void PrintLine(double input) { std::cout << input << std::endl; }
void PrintLine(long input) { std::cout << input << std::endl; }

// Prints a string and adds a new line at the end.
void PrintLine(std::string input) { std::cout << input << std::endl; }

int x = 0;
class MyClass {
 public:
  MyClass() { std::cout << "Constructor" << std::endl; }

  ~MyClass() { std::cout << "Destructor" << std::endl; }
};
int main() {
  std::string text = "Hello world!";
  PrintLine(text);
  PrintLine("Second hello world");
  PrintLine(2);
  PrintLine('a');
  MyClass c;
  for (int i = 0; i < 5; i++) {
    std::cout << "i: " << i << std::endl;
  }

  return 0;
}

