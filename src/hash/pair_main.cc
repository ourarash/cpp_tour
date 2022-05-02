#include <iostream>
#include <map>
#include <string>
#include <vector>

struct MyPerson {
  MyPerson() : name("No Name"), age(0) {}
  MyPerson(const std::string& name_p, int age_p) : name(name_p), age(age_p) {}
  std::string name;
  int age;
};

int main() {
  std::pair<char, int> pair1 = {'A', 4};
  std::pair<char, int> pair2 = {'B', 3};

  std::cout << "pair1.first: " << pair1.first
            << ", pair1.second: " << pair1.second << std::endl;


  std::pair<std::string, MyPerson> person_pair = {"Ari", MyPerson("Ari", 20)};
  std::cout << "person_pair.first: " << person_pair.first << std::endl;

  std::cout << "person_pair.second.age: " << person_pair.second.age
            << std::endl;






  std::map<std::string, int> grades;

  grades["Ari"] = 3;
  grades["Ted"] = 4;
  grades["Jessica"] = 3;

  // vector[2]= 5; ----> O(1) indexing. Finding in vector: O(n)

  // Immutable
  for (const auto& e : grades) {
    std::cout << "e.first: " << e.first << std::endl;
    std::cout << "e.second: " << e.second << std::endl;
  }

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