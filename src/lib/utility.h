#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <string>
// Swaps values of i and j
template <class T>
void Swap(T &i, T &j) {
  T temp = i;
  i = j;
  j = temp;
}
template <class T>
void PrintLine(T input) {
  std::cout << input << std::endl;
}

//-----------------------------------------------------
template <class T>
void PrintArray(T *input, size_t size) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (int i = 0; i < size; i++) {
    const auto &n = input[i];
    count++;
    std::cout << n;
    if (count < size) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}
//-----------------------------------------------------
template <class T>
void PrintVector(std::vector<T> input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}
//-----------------------------------------------------
template <class T>
void Print2dVector(std::vector<std::vector<T>> input) {
  std::cout << "{ " << std::endl;
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[0].size(); j++) {
      std::cout << input[i][j];
      if (j < input[0].size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
  }
  std::cout << " }" << std::endl;
}
//-----------------------------------------------------
template <class T>
void Print(T input, long infinity = INT_MAX) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    if (n == infinity) {
      std::cout << "∞";

    } else {
      std::cout << n;
    }
    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}

// Prints index of items if the item is non zero
template <class T>
void PrintIndexIfNonZero(T input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    if (n != 0) {
      std::cout << count - 1;
    }

    if (count < input.size() && n != 0) {
      std::cout << ", ";
    }
  }
  std::cout << " }" << std::endl;
}
#endif