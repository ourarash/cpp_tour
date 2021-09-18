#include <iostream>
#include <string>
#include <vector>

struct Point {
  int x;
  int y;
  std::string name;
};

void PrintPoint(Point &p) {
  std::cout << "p.x: " << p.x << ", p.y: " << p.y << ", p.name: " << p.name
            << std::endl;
}

int main() {
  Point p1;

  p1.x = 20;
  p1.y = 30;
  p1.name = "My Point 1";

  PrintPoint(p1);

  Point p2;
  p2 = p1;
  p2.x++;
  p2.name = "My Point 2";
  PrintPoint(p2);

  // Doesn't compile
  // if(p1==p2){

  // }
}