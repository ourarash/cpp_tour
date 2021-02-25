#include <iostream>
#include <memory>
#include <string>

struct Person {
  std::string first_name;
  std::string last_name;
  int age;

  Person() { std::cout << "Person constructor" << std::endl; }
  ~Person() { std::cout << "Person destructor" << std::endl; }
  void Talk() {
    std::cout << "Hi, my name is: " << first_name + ' ' + last_name
              << std::endl;
  }

  std::string FullName() { return first_name + ' ' + last_name; }
};

void DoStuff(std::unique_ptr<Person> p) { p->Talk(); }

int main() {
  // Weak pointer going out of scope before shared pointer
  {
    std::unique_ptr<Person> uptr(new Person());

    // Can call functions just like a regular pointer!
    uptr->first_name = "Ari";
    uptr->last_name = "Saif";

    uptr->Talk();
  }

  return 0;
}
