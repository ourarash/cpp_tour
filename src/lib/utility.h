#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <string>
void PrintLine(int input) { std::cout << input << std::endl; }
void PrintLine(char input) { std::cout << input << std::endl; }
void PrintLine(float input) { std::cout << input << std::endl; }
void PrintLine(double input) { std::cout << input << std::endl; }

// Prints a string and adds a new line at the end.
void PrintLine(std::string input) { std::cout << input << std::endl; }

//-----------------------------------------------------
template <class T> void PrintArray(T* input, size_t size) {
  std::cout << "{ ";
  unsigned int count = 0;
  for(int i=0; i<size ; i++) {
    const auto &n = input[i];
    count++;
    std::cout << n;
    if (count < size )
      std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}
//-----------------------------------------------------
template <class T> void PrintVector(std::vector<T> input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size() )
      std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}
#endif