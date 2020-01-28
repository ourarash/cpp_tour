#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>

struct MyPerson {
  MyPerson() : name("No Name"), age(0) {}
  MyPerson(const std::string &name_p, int age_p) : name(name_p), age(age_p) {}
  std::string name;
  int age;
};

int IndexFunction(const std::string &name) {

  if (name == "Tom") {
    return 0;
  }
  if (name == "Alice") {
    return 1;
  }
  if (name == "Bob") {
    return 2;
  }
  if (name == "Ted") {
    return 3;
  }
}

int main() {
  std::vector<MyPerson> persons(4);

  persons[0] = MyPerson("Tom", 12);
  persons[1] = MyPerson("Alice", 18);
  persons[2] = MyPerson("Bob", 15);
  persons[3] = MyPerson("Ted", 57);

  std::cout << "Tom's age: " << persons[IndexFunction("Tom")].age << std::endl;

  persons[IndexFunction("Ted")].age;
}