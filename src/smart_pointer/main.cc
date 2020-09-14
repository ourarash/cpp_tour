#include <iostream>

int divide(int num, int denom) {
  if (denom == 0) {
    throw "Error";
  } else {
    return num / denom;
  }
}

int main() {
  {
    size_t size = 10;
    int* dynamic_array = new int[size];

    for (size_t i = 0; i < size; i++) {
      dynamic_array[i] = divide(1, i);
      std::cout << "dynamic_array[i]: " << dynamic_array[i] << std::endl;
    }

    std::cout << "Deleting the dynamic array." << std::endl;
    delete[] dynamic_array;
  }

  // With exception handling.
  {
    size_t size = 10;
    int* dynamic_array = new int[size];

    try {
      for (size_t i = 0; i < size; i++) {
        dynamic_array[i] = divide(1, i);
        std::cout << "dynamic_array[i]: " << dynamic_array[i] << std::endl;
      }

    } catch (...) {
      std::cout << "Exception!" << '\n';
    }

    std::cout << "Deleting the dynamic array." << std::endl;
    delete[] dynamic_array;
  }
  return 0;
}
