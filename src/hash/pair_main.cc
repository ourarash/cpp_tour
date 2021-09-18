#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "src/lib/utility.h"

struct MyPerson {
  MyPerson() : name("No Name"), age(0) {}
  MyPerson(const std::string &name_p, int age_p) : name(name_p), age(age_p) {}
  std::string name;
  int age;
};

int main() {
  std::map<std::string, int> grades;

  persons["Ari"] = 3;
  persons["Ted"] = 4;
  persons["Jessica"] = 3;

  std::map<std::string, MyPerson> persons;

  persons["Tom"] = MyPerson("Tom", 12);
  persons["Alice"] = MyPerson("Alice", 18);
  persons["Bob"] = MyPerson("Bob", 15);
  persons["Ted"] = MyPerson("Ted", 57);

  std::cout << "Tom's age: " << persons["Tom"].age << std::endl;

  std::pair<std::string, MyPerson> p1("Annie", MyPerson("Annie", 57));
  std::cout << "p1.first: " << p1.first << std::endl;
  std::cout << "p1.second.age: " << p1.second.age << std::endl;

  persons.insert(p1);

  persons["Annie"] = MyPerson("Annie", 57);

  for (auto n : persons) {
    std::cout << "key: " << n.first << std::endl;
    std::cout << "value: " << n.second.age << std::endl;
  }

  std::pair<std::string, int> p1("Ari", 3);
  std::pair<std::string, int> p2("Ted", 4);
  std::cout << "p1.first: " << p1.first << std::endl;
  std::cout << "p1.second: " << p1.second << std::endl;
}