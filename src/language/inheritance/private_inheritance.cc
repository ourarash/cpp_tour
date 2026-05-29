#include <iostream>
#include <string>
class Person {
 public:
  std::string name_;
};

class Student : private Person {};  // inheritance is now private
void eat(const Person& p);          // anyone can eat
void study(const Student& s);       // only students study

// in contrast to public inheritance,
// compilers will generally not convert a derived class object (such as Student)
// into a base class object (such as Person) if the inheritance relationship
// between the classes is private.
// The second rule is that members inherited from a private base class
// become private members of the derived class, even if they were protected or
// public in the base class.
// Private inheritance means is-implemented-in-terms-of.
int main(int argc, char const* argv[]) {
  Person p;   // p is a Person
  Student s;  // s is a Student
  eat(p);     // fine, p is a Person
  eat(s);     // error! a Student isn't a Person
  return 0;
}
