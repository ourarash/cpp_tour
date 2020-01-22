#include "src/lib/utility.h"
#include <iostream>
#include <string>

void InitializeArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = i;
  }
}

int main() {
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