#include <iostream>
#include <string>
#include <vector>

// Global variable
int global_variable = 6;

class Person {
 public:
  Person() { std::cout << "I am the constructor" << std::endl; }

  ~Person() { std::cout << "I am the distructor" << std::endl; }
  std::string name;
};

void MyFunc() {
  int a;
  {
    Person p;
    // Do something with p
  }

  std::cout << "global_variable: " << global_variable << std::endl;
}

int main() {
  // Scope
  {
    int a;
    a = 109;
    // std::cout << "a: " << a << std::endl;

    {
      Person p;
      int a = 1000;
      // std::cout << "a: " << a << std::endl;
    }

    std::cout << "a: " << a << std::endl;
  }

  // std::cout << "a: " << a << std::endl;

  // std::cout << "i: " << i << std::endl;

  // int global_variable = 10;  // This is now a local variable!
  // std::cout << "global_variable: " << global_variable << std::endl;
  // MyFunc();
  // //--------------------------------------------------
  // Inside control blocks
  int i = 1;
  for (int i = 0; i < 10; i++) {
    // scope of the i in for loop is only here
    std::cout << "i: " << i << std::endl;
  }
  i++;
  std::cout << "i: " << i << std::endl;
  // //--------------------------------------------------
  // // Inside blocks
  // {
  //   int j = 1;
  //   for (int j = 0; j < 10; j++) {
  //     std::cout << "j: " << j << std::endl;
  //   }
  // }
  // j++; // j is not defined here!
}