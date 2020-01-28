#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
  // c string array
  char name[10] = "tommy";
  std::cout << name << std::endl;

  for (int i = 0; i < 10; i++) {
    std::cout << i << ". " << name[i] << std::endl;
  }

  // basic string
  std::string first_name = "tommy";
  std::string last_name = "trojan";
  std::string full_name = first_name + " " + last_name;

  std::cout << "full_name: " << full_name << std::endl;

  // convert to string
  int first_digit = 6;
  int second_digit = 5;
  std::string first_digit_str = std::to_string(first_digit);
  std::string second_digit_str = std::to_string(second_digit);

  std::string both_digits = second_digit_str + first_digit_str;
  std::cout << "both_digits: " << both_digits << std::endl;

  // push back
  std::string a;

  a.push_back('t');
  std::cout << "a: " << a << std::endl;
  a.push_back('o');
  std::cout << "a: " << a << std::endl;

  // Get the size (or length)
  std::cout << "a.size(): " << a.size() << std::endl;

  a.pop_back();

  std::cout << "a: " << a << std::endl;

  // getline
  std::string str;
  getline(std::cin, str);
  std::cout << "you entered: " << str << std::endl;

  // c_str
  std::string str("This is a sample string.");

  char *cstr = new char[str.length() + 1];  // dynamic array
  std::strcpy(cstr, str.c_str());
  return 0;
}