#include <iostream>
#include <string>
#include <vector>
class Person {
 public:
  // Every constructor should initialize _ssn
  Person(int ssn) : _age(20), _ssn(ssn) {}
  Person(int ssn, int age) : _age(age), _ssn(ssn) {}

  std::string first_name_;
  std::string last_name_;
  int _age;
  const int _ssn;  // const member variable

  // It doesn't change any member variables
  int size() const {
    std::cout << "const size" << std::endl;
    // first_name_ = "Ari";
    return first_name_.size() + last_name_.size() + sizeof(_age);
  }

  int size() {
    std::cout << "non const size" << std::endl;
    first_name_ = "Ari";
    return first_name_.size() + last_name_.size() + sizeof(_age);
  }
};

int main() {
  {
    const Person r(/*_ssn=*/354545454, /*age=*/21);
    r.size();
  }

  {
    Person r(/*_ssn=*/354545454, /*age=*/21);
    r.size();
  }
  {
    Person p(/*_ssn=*/354545454);
    p.first_name_ = "Tommy";
    p.last_name_ = "Trojan";

    // Const object
    const Person q(/*_ssn=*/354545454);
    // q._age = 21; // Don't modify const object!
    std::cout << "q._age: " << q._age << std::endl;

    // Initializing
    const Person r(/*_ssn=*/354545454, /*age=*/21);
    std::cout << "r._ssn: " << r._ssn << std::endl;
    std::cout << "r._age: " << r._age << std::endl;
  }

  return 0;
}