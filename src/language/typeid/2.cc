#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;
class Person {
 public:
  // virtual ~Person() {}
  void Talk() { std::cout << "Person talking!" << std::endl; }
};
class Employee : public Person {
  void Talk() { std::cout << "Employee Talking!" << std::endl; }
};

int main(int argc, char const* argv[]) {
  // Later...
  Person* ptr = new Employee();

  ptr->Talk();

  // Outputs "class Person"
  std::cout << typeid(*ptr).name() << std::endl;

  return 0;
}
