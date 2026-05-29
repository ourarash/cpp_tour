#include <exception>
#include <iostream>

class AA {};
struct ExceptThis : public std::exception {};
void fb();
void fc();

void fa() {
  try {
    AA myAA;
    fb();
  } catch (std::exception& e) {
    std::cout << "Uh oh\n";
  }
}
void fb() {
  try {
    AA myAA2;
    fc();
  } catch (const char* e) {
    std::cout << "Not good\n";
  }
}
void fc() { throw ExceptThis(); }
