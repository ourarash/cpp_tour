#include <iostream>
#include <vector>
int main() {
  // lambda expression to print vector
  std::vector<int> my_vector = {1, 2, 3, 4, 5, 6};

  [](const std::vector<int> &v) -> void {
    for (auto n : v) {
      std::cout << "n: " << n << std::endl;
    }
  }(my_vector);

  // Capturing everything by reference
  [&]() {
    for (auto n : my_vector) {
      std::cout << "n: " << n << std::endl;
    }
  }();

  // Capturing my_vector by reference
  [&my_vector]() {
    for (auto n : my_vector) {
      std::cout << "n: " << n << std::endl;
    }
  }();

   // Capturing all by value
  [=]() {
    for (auto n : my_vector) {
      std::cout << "n: " << n << std::endl;
    }
  }();

   // Capturing all by value
  [=]() {
    for (auto n : my_vector) {
      std::cout << "n: " << n << std::endl;
    }
  }();

  return 0;
}