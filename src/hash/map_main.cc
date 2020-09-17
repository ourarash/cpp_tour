#include <iostream>
#include <map>
#include <pair>
#include <string>
#include <vector>

struct MyPerson {
  MyPerson() : name("No Name"), age(0), phone_number("000-00-0000") {}
  MyPerson(const std::string &name_p, int age_p) : name(name_p), age(age_p) {}
  std::string name;
  int age;
  std::string phone_number;
};

int main() {
  std::map<std::string, MyPerson> persons;

  persons["Tom"] = MyPerson("Tom", 12, "310-888-8889");
  persons["Tom"].age = 18;
  persons["Tom"].age = 25;

  persons["Alice"] = MyPerson("Alice", 18);
  persons["Bob"] = MyPerson("Bob", 15);
  persons["Ted"] = MyPerson("Ted", 57);

  std::cout << "persons.count(" Tom "): " << persons.count("Tom") << std::endl;
  std::cout << "persons.size(): " << persons.size() << std::endl;

  std::cout << "Tom's age: " << persons["Tom"].age << std::endl;

  std::pair<std::string, MyPerson> persons["Annie"] = MyPerson("Annie", 55);
}