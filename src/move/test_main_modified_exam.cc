#include <iostream>
#include <set>
#include <string>
#include <vector>

struct Test {
  // Default constructor
  Test() {
    std::cout << "Constructor" << std::endl;
    mValue = 0;
  }

  // Copy constructor
  Test(const Test &rhs) {
    std::cout << "Copy Constructor" << std::endl;
    mName = rhs.mName;
    mValue = rhs.mValue;
  }

  // Copy Assignment
  Test &operator=(const Test &rhs) {
    std::cout << "Copy Assignment" << std::endl;
    mName = rhs.mName;
    mValue = rhs.mValue;
    return *this;
  }

  // Move constructor
  Test(Test &&rhs)
      : mName(std::move(rhs.mName)), mValue(std::move(rhs.mValue)) {
    std::cout << "Move Constructor" << std::endl;
  }

  // Move Assignment
  Test &operator=(Test &&rhs) {
    std::cout << "Move Assignment" << std::endl;
    mName = std::move(rhs.mName);
    mValue = std::move(rhs.mValue);
    return *this;
  }

  std::string mName;
  int mValue;
};

Test doStuff() {
  Test temp;
  temp.mName = "Hello World!";
  return temp;
}

int main() {
  Test c;
  c = doStuff();
}

std::vector<int> MyFunction(std::vector<unsigned int> very_large_input) {
  std::vector<int> result;

  for (auto i = 0; i < very_large_input.size(); i++) {
    for (auto j = 0; j < very_large_input.size(); j++) {
      for (auto k = 0; k < very_large_input.size(); k++) {
        for (auto l = 0; l < very_large_input.size(); l++) {
          unsigned long sum = very_large_input[i] + very_large_input[j] +
                              very_large_input[k] + very_large_input[l];
          if ((i + j + k + l) % 2 == 0) {
            result.push_back(sum);
          }
        }
      }
    }
  }
  return result;
}
