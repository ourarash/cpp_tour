#include <iostream>
#include <map>
#include <string>

//-----------------------------------------------------
#include <initializer_list>

int addList(const std::initializer_list<int>& list) {
  int retVal = 0;
  // Range based for loop
  for (auto i : list) {
    retVal += i;
  }

  return retVal;
}
//-----------------------------------------------------
void printMonths(
    const std::initializer_list<std::pair<int, std::string>>& list) {
  for (auto i : list) {
    std::cout << i.first << ":" << i.second << std::endl;
  }
}

int main(int argc, char const* argv[]) {
  std::cout << addList({1, 1, 2, 3, 5, 8, 13}) << std::endl;
  printMonths({
      {1, "January"}, {2, "February"}, {3, "March"},
      // ...
  });

  return 0;
}
