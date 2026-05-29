// #include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>

void InitializeArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = i;
  }
}

void InitializeVector(std::vector<int> &input) {
  for (int i = 0; i < input.size(); i++) {
    input[i] = i;
  }
}

int main() {
  {
    int *arr;

    // arr = new int;
    arr = new int[10];
    // delete arr; // Don't do this!















    // .. 100 lines later
    // What is the size of arr?

    delete[] arr;
  }

  int constant_size_array[10];

  int *arr = nullptr;
  int size = 1000;

  // check if arr is not allocated
  // check if arr is pointing to an invalid location.
  if (arr == nullptr) {
    std::cout << "arr is not allocated yet." << std::endl;
  } else {
    std::cout << "arr is allocated." << std::endl;
  }
  std::cout << "Please enter the size: " << std::endl;
  std::cin >> size;

  arr = new int[size];

  arr[1] = 10;

  size = 0;

  if (arr == nullptr) {
    std::cout << "arr is not allocated yet." << std::endl;
  } else {
    std::cout << "arr is allocated." << std::endl;
  }
  std::cout << "arr: " << arr << std::endl;

  InitializeArray(arr, size);
  // PrintArray(arr, size);

  delete[] arr;

  // what's the size of constant_size_array??
  // constant_size_array.size() doesn't exist!

  size = 10;
  // What about size of arr?

  return 0;
}
