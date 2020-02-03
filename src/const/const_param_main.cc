#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>

int CalculateTax(int income) {
  income = income - 20; // It changes the copy
  return income * 0.3;
}

int CalculateTaxRef(int &income) {
  income = income - 20; // It changes the original!
  return income * 0.3;
}

int CalculateTaxConstRef(const int &income) {
  // income = income - 20; // Don't touch my income!
  return income * 0.3;
}

int main() {

  int i = 2000;
  
  int tax = CalculateTaxConstRef(i);
  std::cout << "i: " << i << std::endl;

  return 0;
}