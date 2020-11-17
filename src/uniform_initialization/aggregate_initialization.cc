#include <iostream>
#include <list>
#include <string>
#include <vector>

//-----------------------------------------------------
struct Point {
  int x;
  int y;
  int z;
};

struct Test2 {
  Point topLeft;
  Point botRight;
};

int main() {
  Point t{50, -50, 25}; // Aggregate initialization

  // t.x = 50;
  // t.y = -50;

  Test2 t2{
      {5, 10, 15},  // Top left
      {2, 4, 6},    // Bottom right
  };

  // STL
  // Initialize a vector of even numbers
  std::vector<int> v{2, 4, 6, 8, 10};
  std::vector<int> v2{2, 4, 6, 8, 10, 11};
  std::vector<int> v4{2, 4, 6, 8, 10, 11, 12};

  // Initialize a list of odd numbers
  std::list<int> l{1, 3, 5, 7, 9};

  // Create a pair
  std::pair<std::string, int> p{"Hello", 5};

  // Vector of pairs
  std::vector<std::pair<int, std::string>> months{
      {1, "January"}, {2, "February"}, {3, "March"},
      // ...
  };
}