#include "src/lib/utility.h"
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

  for (const auto &p : persons) {
    std::cout << "p: " << p << std::endl;
  }
}