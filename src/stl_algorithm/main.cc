#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#include "src/lib/utility.h"

struct Person {
  std::string first_name;
  std::string last_name;
  int age;
  int ssn;
};

bool GreaterThanSSN(Person p1, Person p2) { return (p1.ssn <= p2.ssn); }

bool GreaterThanAge(const Person& p1, const Person& p2) {
  return (p1.age <= p2.age);
}
// std::vector<Person> persons;
// std::sort(persons.begin(), persons.end(), GreaterThanSSN);
// std::sort(persons.begin(), persons.end(), GreaterThanAge);

bool IsOdd(int i) { return ((i % 2) == 1); }
bool IsEven(int i) { return ((i % 2) == 0); }
bool LessThanOrEqual(int a, int b) { return a <= b; }
bool GreaterThan(int a, int b) { return a > b; }

int Multiply(int i, int j) { return i * j; }
int MultiplyBy10(int i) { return i * 10; }

int main() {
  {
    std::vector<int> v = {12, -2, 0, 0, 1, 12, 5, 3, 13, 3, 5};
    auto count = std::count_if(v.begin(), v.end(), IsOdd);
    std::cout << "count_if: " << count << std::endl;
  }

  // Find
  {
    std::vector<int> v = {12, -2, 0, 13, 3, 5};
    auto it2 = v.begin();
    it2++;

    auto it = std::find(it2, v.end(), 12);

    if (it != v.end()) {
      const auto& n = *it;
      std::cout << "Found n: " << n << std::endl;

      it++;

      std::cout << "*it: " << *it << std::endl;
      v.insert(it, 20);

    } else {
      std::cout << "Didn't find." << std::endl;
    }
  }

  // Sort
  {
    std::vector<int> v = {12, -2, 0, 13, 3, 5};
    std::sort(v.begin(), v.end());
    Print(v);
  }

  // Sort
  {
    std::vector<int> v = {12, -2, 0, 13, 3, 5};
    std::sort(v.begin(), v.end(), GreaterThan);
    Print(v);
  }

  // Reverse
  {
    std::vector<int> v = {12, -2, 0, 13, 3, 5};
    std::reverse(v.begin(), v.end());
    Print(v);
  }

  // Count
  {
    std::vector<int> v = {12, -2, 0, 0, 1, 12, 5, 3, 13, 3, 5};
    auto count = std::count(v.begin(), v.end(), 5);
    std::cout << "count: " << count << std::endl;
  }

  // Count_if

  {
    std::vector<int> v = {12, -2, 0, 0, 1, 12, 5, 3, 13, 3, 5};
    auto count = std::count_if(v.begin(), v.end(), IsOdd);
    std::cout << "count: " << count << std::endl;
  }

  // Accumulate
  {
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    auto sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "sum: " << sum << std::endl;
  }

  // Accumulate 2
  {
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    auto sum = std::accumulate(v.begin(), v.end(), /*init=*/1,
                               /*binary_op=*/Multiply);
    std::cout << "mult: " << sum << std::endl;
  }

  {
    std::vector<int> v = {1, 2, 3, 4, 5, 6};

    std::vector<int> v2(
        v.size());  // Constructor! The size of the vector; Initialize to 0

    std::transform(v.begin(), v.end(), v2.begin(), MultiplyBy10);

    std::transform(v.begin(), v.end(), v.begin(), MultiplyBy10);

    Print(v2);
    Print(v);
  }

  // Add up all odd numbers
  // {
  //   std::vector<int> v = {1, 2, 3, 4, 5, 6};

  //   auto all_odd_number = std::copy_if(v.begin(), v.end(), v.begin(), IsOdd);

  //   // define all_odd_number_multiplied_by_10
  //   std::transform(all_odd_number.begin(), all_odd_number.end(),
  //                  all_odd_number_multiplied_by_10.begin(), MultiplyBy10);

  //   auto sum = std::accumulate(all_odd_number_multiplied_by_10.begin(),
  //                              all_odd_number_multiplied_by_10.end(), 0);
  // }

  return 0;
}