#include "src/lib/utility.h"
#include <iostream>
#include <string>

struct Person {
  std::string first_name;
  std::string last_name;
  int age;
};

void InitializeArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = i;
  }
}

void InitializeArray2(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = i;
  }
}

void InitializeArray3(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    *(arr + i) = i * 10;
  }
}

int main() {

  int arr[8];
  InitializeArray(arr, 8);
  PrintArray(arr, 8);

  arr[0] = 5;
  arr[2] = -10;
  PrintArray(arr, 8);

  // Reading from index
  int x = arr[0];
  std::cout << "x: " << x << std::endl;

  InitializeArray2(arr, 8);
  PrintArray(arr, 8);

  *arr = -100;
  PrintArray(arr, 8);

  InitializeArray3(arr, 8);
  PrintArray(arr, 8);

  // Using a pointer instead of arr
  int *p = &arr[0];
  std::cout << "arr: " << arr << std::endl;
  std::cout << "p: " << arr << std::endl;

  return 0;
}