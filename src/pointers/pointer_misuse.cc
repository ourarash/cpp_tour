#include <iostream>
#include <string>

int main() {
  {
    int i; // Static variable
    std::cout << "Please enter a value:";
    std::cin >> i;
    if (i >= 10) {
      int *p = new int;
      *p = i;
      *p++;
      std::cout << "*p: " << *p << std::endl;
      delete p;
    } else {
      std::cout << "i was less than 10" << std::endl;
    }
  }
  {
    int j;
    int i;  // Unknown value ---> garbage.

    std::cout << "i: " << i << std::endl;
    std::cout << "j: " << j << std::endl;
  }

  {
    int *p;  // The value is garbage

    std::cout << "p: " << p << std::endl;
  }

  {
    int *p = nullptr;  // The value is a known value
    std::cout << "p: " << p << std::endl;

    // 10000 lines later...
    // I can find out if p is still uninitialized.
    if (p == nullptr) {
    }
  }

  {
    int i = 1;
    int *p = &i;

    *p = 10;

    std::cout << "p: " << p << std::endl;
    std::cout << "*p: " << *p << std::endl;
    std::cout << "i: " << i << std::endl;
  }
  std::cout << "---------------------------------------------------------------"
               "----------------"
            << std::endl;
  {
    int *p;
    std::cout << "p: " << p << std::endl;

    p = new int;  // Borrow from the bank

    std::cout << "p: " << p << std::endl;

    *p = 11;

    std::cout << "*p: " << *p << std::endl;

    delete p;  // Return it to the bank.
    std::cout << "p: " << p << std::endl;

    // Undefined Behavior: crash, segmentation fault, nuclear explosion!
    std::cout << "*p: " << *p << std::endl;
  }

  {
    // Uninitialized pointer
    int *p;

    std::cout << "p: " << p << std::endl;

    // Spending money that you don't have!
    // Undefined behavior!
    std::cout << "*p: " << *p << std::endl;
  }

  {
    // Null pointer
    int *p = nullptr;

    std::cout << "p: " << p << std::endl;

    // Undefined behavior!
    std::cout << "*p: " << *p << std::endl;
  }

  // {
  //   // Some random made up number
  //   int *p = 15;
  //   std::cout << "p: " << p << std::endl;

  //   // Might be Undefined behavior!
  //   std::cout << "*p: " << *p << std::endl;
  // }

  {
    // Dereferencing a deleted pointer.
    int *p = new int;
    *p = 10;
    std::cout << "p: " << p << std::endl;
    std::cout << "*p: " << *p << std::endl;

    delete p;

    std::cout << "p: " << p << std::endl;

    // Undefined behavior!
    std::cout << "*p: " << *p << std::endl;
  }

  {
    // Double deleting.
    int *p = new int;
    std::cout << "p: " << p << std::endl;
    std::cout << "*p: " << *p << std::endl;

    delete p;

    std::cout << "p: " << p << std::endl;
    std::cout << "*p: " << *p << std::endl;

    delete p;  // Undefined behavior.

    std::cout << "*p: " << *p << std::endl;
    std::cout << "p: " << p << std::endl;
  }

  {
    // Memory leak + lost address + deleting static memory!
    int i = 6;
    int *p = new int;
    *p = 5;
    std::cout << "p: " << p << std::endl;
    std::cout << "*p: " << *p << std::endl;

    p = &i;  // The address to the new location is lost forever!
    delete p;
  }

  {
    int i = 6;
    int *p = new int;
    *p = 5;
    std::cout << "p: " << p << std::endl;
    std::cout << "*p: " << *p << std::endl;

    int *q = p;
    p = &i;
    delete q;  // This is ok!
  }

  {
    int *p = new int;
    int *q = new int[10];
    q[5] = 7;
  }
  {
    int *p = new int;
    delete[] p;
  }

  {
    int *p = new int[10];
    delete p;
  }

  return 0;
}
