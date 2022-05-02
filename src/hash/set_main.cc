#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
  std::set<std::string> persons;

  persons.insert("Zane");
  persons.insert("Tom");
  persons.insert("Alice");
  persons.insert("Bob");
  persons.insert("Ted");
  persons.insert("Ted");
  persons.insert("Ted");
  persons.insert("Ted");
  persons.insert("Ted");
  persons.insert("Ted");

  std::cout << "persons.size: " << persons.size() << std::endl;
  for (auto& p : persons) {
    std::cout << "p: " << p << std::endl;
  }

  std::cout << "persons.count(\"Ted\"): " << persons.count("Ted") << std::endl;
  std::cout << "persons.count(\"Ari\"): " << persons.count("Ari") << std::endl;
}
