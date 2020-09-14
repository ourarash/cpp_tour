#include <iostream>
#include <memory>
#include <string>

struct Person {
  std::string first_name;
  std::string last_name;
  int age;

  Person() { std::cout << "Person constructor" << std::endl; }
  ~Person() { std::cout << "Person destructor" << std::endl; }

  std::string FullName() { return first_name + ' ' + last_name; }
};

int main() {
  // Weak pointer going out of scope before shared pointer
  {
    std::unique_ptr<Person> p_shared1(new Person());

    // Can call functions just like a regular pointer!
    p_shared1->first_name = "Ari";
    p_shared1->last_name = "Saif";

    std::cout << "p_shared1->FullName(): " << p_shared1->FullName()
              << std::endl;
  }

  return 0;
}
