#include <iostream>
#include <string>
#include <vector>

// Global variable
int variable = 6;

class Person {
 public:
  Person() { std::cout << "I am the constructor" << std::endl; }

  ~Person() { std::cout << "I am the distructor" << std::endl; }
  std::string name;
};

void MyFunc() {
  variable++;
  int a;
  {
    Person p;
    // Do something with pd
  }
  // std::cout << "p.name: " << p.name << std::endl;

  std::cout << "global_variable: " << global_variable << std::endl;
}

int main() {
  int k = 0;
  {
    for (int i = 0; i < 1000; i++) {
      int j = i += 2;
    }

    if (k == 1) {
      int x = k;
    }

    std::cout << "j: " << j << std::endl;
    std::cout << "i: " << i << std::endl;
  }

  std::cout << "k: " << k << std::endl;
  // Scope
  {
    {
      Person p;
      int a = 1000;
      // std::cout << "a: " << a << std::endl;
    }

    int a;
    a = 109;
    std::cout << "a: " << a << std::endl;

    {
      Person p;
      int a = 1000;
      std::cout << "a: " << a << std::endl;
    }

    std::cout << "a: " << a << std::endl;
  }

  // std::cout << "i: " << i << std::endl;

  // int global_variable = 10;  // This is now a local variable!
  // std::cout << "global_variable: " << global_variable << std::endl;
  // MyFunc();
  // //--------------------------------------------------
  // Inside control blocks

  for (int i = 0; i < 10; i++) {
    // scope of the i in for loop is only here
    std::cout << "i: " << i << std::endl;
  }

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