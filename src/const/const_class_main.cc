#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>
class Person {

public:
  // Every constructor should initialize _ssn
  Person(int ssn) : _ssn(ssn), _age(20) {}
  Person(int ssn, int age) : _ssn(ssn), _age(age) {}

  std::string _first_name;
  std::string _last_name;
  int _age;
  const int _ssn; // const member variable

  // It doesn't change any member variables
  int size() const {
    return _first_name.size() + _last_name.size() + sizeof(_age);
  }
};

int main() {

  Person p(/*_ssn=*/354545454);
  p._first_name = "Tommy";
  p._last_name = "Trojan";

  // Const object
  const Person q(/*_ssn=*/354545454);
  // q._age = 21; // Don't modify const object!
  std::cout << "q._age: " << q._age << std::endl;

  // Initializing
  const Person r(/*_ssn=*/354545454, /*age=*/21);
  std::cout << "r._ssn: " << r._ssn << std::endl;
  std::cout << "r._age: " << r._age << std::endl;

  return 0;
}