#include "src/lib/utility.h"
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
  int constant_size_array [10];

  int *arr;
  int size;

  std::cout << "Please enter the size: " << std::endl;

  std::cin >> size;

  arr = new int[size];

  InitializeArray(arr, size);
  PrintArray(arr, size);

  delete [] arr;

  return 0;
}