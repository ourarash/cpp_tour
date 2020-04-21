#ifndef UTILITY_H
#define UTILITY_H
#include <cmath>
#include <iostream>
#include <numeric>
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

template <class T>
void PrintVectorOfString(T input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;

    std::cout << "\"" << n << "\"";

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

template <class T>
void PopulateVector(std::vector<T> &v) {
  unsigned long i = 0;
  for (auto &e : v) {
    e = pow(-1, i % 2) * i;
    i++;
  }
}

template <class T>
void PopulateVector(std::vector<T> &v, int number_of_elements) {
  for (uint64_t i = 0; i < number_of_elements; i++) {
    T e = pow(-1, i % 2) * i;
    v.push_back(e);
  }
}

// Multi threading
template <class T>
void AccumulateVector(const std::vector<T> &v, T &sum, T start_index,
                      T end_index) {
  sum = std::accumulate(v.begin() + start_index, v.begin() + end_index, T(0));
}

template <class T>
T AccumulateVector(const std::vector<T> &v) {
  T sum = 0;
  for (auto ps : v) {
    sum += ps;
  }
  return sum;
}

void CalculateShort(int64_t &sum, int64_t start, int64_t end) {
  sum = 0;
  for (auto i = start; i < end; i++) {
    sum += pow(-1, i % 2);
  }
}

class CalculateShortFunctor {
 public:
  void operator()(int64_t start, int64_t end) {
    _sum = 0;
    for (auto i = start; i < end; i++) {
      _sum += pow(-1, i % 2);
      // _sum += i;
    }
    std::cout << _sum << std::endl;
  }
  int64_t _sum;
};

class AccumulateFunctor {
 public:
  void operator()(int64_t start, int64_t end) {
    _sum = 0;
    for (auto i = start; i < end; i++) {
      _sum += i;
    }
    std::cout << _sum << std::endl;
  }
  int64_t _sum;
};

uint64_t AccumulateRange(uint64_t &sum, uint64_t start, uint64_t end) {
  sum = 0;
  for (auto i = start; i < end; i++) {
    sum += i;
  }
  return sum;
}

uint64_t GetRangeSum(uint64_t start, uint64_t end) {
  uint64_t sum = 0;
  for (auto i = start; i < end; i++) {
    sum += i;
  }
  return sum;
}
#endif