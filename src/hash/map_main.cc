#include "src/lib/utility.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <pair>


struct MyPerson {
  MyPerson() : name("No Name"), age(0) {}
  MyPerson(const std::string &name_p, int age_p) : name(name_p), age(age_p) {}
  std::string name;
  int age;
};

int main() {
  std::map<std::string, MyPerson> persons;

  persons["Tom"] = MyPerson("Tom", 12);
  persons["Alice"] = MyPerson("Alice", 18);
  persons["Bob"] = MyPerson("Bob", 15);
  persons["Ted"] = MyPerson("Ted", 57);

  std::cout << "Tom's age: " << persons["Tom"].age << std::endl;

  std::pair<std::string, MyPerson> 
  persons["Annie"] = MyPerson("Annie", 55);
}