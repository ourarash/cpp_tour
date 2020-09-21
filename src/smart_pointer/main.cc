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

    // Generates an exception
    for (size_t i = 0; i < size; i++) {
      dynamic_array[i] = i;
      std::cout << "dynamic_array[i]: " << dynamic_array[i] << std::endl;
    }

    std::cout << "Deleting the dynamic array." << std::endl;

    // What if we forget this line?
    // Memory leak
    delete[] dynamic_array;
  }

  std::cout << "------------------------------------------" << std::endl;
  {
    size_t size = 10;
    int* dynamic_array = new int[size];

    // Generates an exception
    for (size_t i = 0; i < size; i++) {
      dynamic_array[i] = i;
      std::cout << "dynamic_array[i]: " << dynamic_array[i] << std::endl;
    }

    std::cout << "Deleting the dynamic array." << std::endl;

    // delete the pointer
    delete[] dynamic_array;
    // dynamic_array = nullptr;

    // 10000 lines later...
    // delete the pointer again.
    // delete[] dynamic_array;
  }

  std::cout << "------------------------------------------" << std::endl;
  // With exception
  {
    size_t size = 10;
    int* dynamic_array = new int[size];

    // Generates an exception
    for (size_t i = 0; i < size; i++) {
      dynamic_array[i] = divide(1, i);
      std::cout << "dynamic_array[i]: " << dynamic_array[i] << std::endl;
    }

    std::cout << "Deleting the dynamic array." << std::endl;

    // Do we ever run this line?
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
