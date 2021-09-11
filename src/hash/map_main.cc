#include <iostream>
#include <map>
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
  MyPerson p;
  p.age = 10;
  p.name = "Ari";


  std::map<int, std::string> t2;

  std::map<std::string, int> turns;
  std::pair<std::string, int> my_pair{"Tommy", 10};

  std::cout << "my_pair.first: " << my_pair.first << std::endl;
  std::cout << "my_pair.second: " << my_pair.second << std::endl;

  turns["Ted"] = 2;
  turns["Ari"] = 1;
  turns["Beth"] = 3;
    
  //   Key   Value
  // ----- |-------
  //   Ted |  2
  //   Ari |  1
  //   Beth|  3

  std::cout << "turns.size(): " << turns.size() << std::endl;

  if (turns.count("Max") == 1) {
  }

  for (auto &e : turns) {
    auto key = e.first;
    auto value = e.second;

    std::cout << "turns[key]: " << turns[key] << std::endl;
  }

  std::map<std::string, MyPerson> persons;

  // persons["Tom"] = MyPerson("Tom", 12, "310-888-8889");
  persons["Tom"].age = 18;
  persons["Tom"].age = 25;

  persons["Alice"] = MyPerson("Alice", 18);
  persons["Bob"] = MyPerson("Bob", 15);

  persons["Ted"] = MyPerson("Ted", 57);
  persons["Ted"] = MyPerson("Ted", 10);

  std::cout << "persons.count(\" Ted \"): " << persons.count("Ted")
            << std::endl;

  std::cout << "persons.count(\" Ari \"): " << persons.count("Ari")
            << std::endl;

  std::cout << "persons.size(): " << persons.size() << std::endl;

  std::cout << "Tom's age: " << persons["Tom"].age << std::endl;

  // std::pair<std::string, MyPerson> persons["Annie"] = MyPerson("Annie", 55);
}
