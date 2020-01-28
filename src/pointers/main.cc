#include <iostream>
#include <string>

struct Person {
  std::string first_name;
  std::string last_name;
  int age;
};

int main() {
  
  int i = 10;
  int *p = &i;
  std::cout << "i: " << i << std::endl;
  std::cout << "p: " << p << std::endl;

  (*p)++;
  std::cout << "i: " << i << std::endl;

  p++;
  std::cout << "p: " << p << std::endl;
  std::cout << "i: " << i << std::endl;

  std::cout << "------------------------------------------" << std::endl;
  // Using with struct
  Person person;
  Person *person_ptr = &person;
  (*person_ptr).first_name = "Tommy";
  person_ptr->last_name = "Trojan";

  std::cout << "person_ptr->first_name: " << person_ptr->first_name
            << ", person_ptr->last_name: " << person_ptr->last_name
            << std::endl;

  return 0;
}