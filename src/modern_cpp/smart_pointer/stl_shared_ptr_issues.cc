#include <iostream>
#include <string>

struct Person {
  std::string first_name;
  std::string last_name;
  int age;

  Person() { std::cout << "Person constructor" << std::endl; }
  ~Person() { std::cout << "Person destructor" << std::endl; }

  void Talk() { std::cout << "Hi, my name is: " << FullName() << std::endl; }

  std::string FullName() { return first_name + ' ' + last_name; }
};

void DoStuff(std::shared_ptr<Person> p) { p->Talk(); }

void DoStuff2(std::shared_ptr<Person>& p) { p->Talk(); }

void DoStuff(Person* p) { p->Talk(); }

int main() {
  {  // Construct a scoped pointer to a newly-allocated object
    auto pw = new Person;              // pw is raw ptr
    std::shared_ptr<Person> spw1(pw);  // create control
    // block for *pw
    spw1->first_name = "Ari";
    {
      std::shared_ptr<Person> spw2(pw);  // create 2nd
                                         // control block
                                         // for *pw!
    }
    std::cout << "spw1->first_name: " << spw1->first_name << std::endl;
    // Undefined behavior !!
  }

  return 0;
}
