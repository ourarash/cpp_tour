#include <iostream>
#include <string>
#include <vector>

std::string encrypt(std::string s) { return s; }

class Person {
 public:
  Person() { name_ = "UNKNOWN"; }
  Person(const Person& other) {}

  ~Person() { std::cout << "Destructor!" << std::endl; }

  std::string GetSSN() {
    return social_security_number_.empty() ? "NONE" : createStars();
  }

  void SetSSN(const std::string& ssn) {
    social_security_number_ = encrypt(ssn);
  }

  void Talk() { std::cout << "Hi, my name is: " << name_ << std::endl; }

  void TellMyAge() {
    if (age_ > 18) {
      std::cout << "I'm over 18" << std::endl;
    } else {
      std::cout << "I'm under 18" << std::endl;
    }
  }

  std::string name_;

 private:
  int age_;
  std::string social_security_number_;

  std::string createStars() { return "***-**-****"; }
};

void myFunction(Person p) { std::cout << "p.name_: " << p.name_ << std::endl; }

int main() {
  {
    Person p;

    std::cout << "p.name_: " << p.name_ << std::endl;
    p.name_ = "Ari";
    std::cout << "p.name_: " << p.name_ << std::endl;

    Person* q;
    q = new Person;

    myFunction(p);
    Person p2 = p;

    // Doesn't compile:
    // std::cout << "p.social_security_number_: " << p.social_security_number_
    // << std::endl;
    std::cout << "p.GetSSN(): " << p.GetSSN() << std::endl;
    p.SetSSN("123-23-1234");
    std::cout << "p.GetSSN(): " << p.GetSSN() << std::endl;
  }
  std::cout << "Exitting scope" << std::endl;
}