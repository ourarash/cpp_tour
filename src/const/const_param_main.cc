#include <iostream>
#include <string>
#include <vector>

// Copies, but doesn't change the original
int CalculateTax(int income) {
  income = income - 20; // It changes the copy
  return income * 0.3;
}

// Doesn't copy, but changes original
int CalculateTaxRef(int &income) {
  income = income - 20; // It changes the original!
  return income * 0.3;
}

// Doesn't change, and doesn't copy
int CalculateTaxConstRef(const int &income) {
  // income = income - 20; // Don't touch my income!
  return income * 0.3;
}

int main() {

  int i = 2000;
  
  int tax = CalculateTaxRef(i);

  std::cout << "i: " << i << std::endl;

  return 0;
}