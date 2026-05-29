#include <iostream>
#include <string>
#include <vector>

// Copies, but doesn't change the original
int CalculateTax(int income) {
  income = income - 20;  // It changes the copy
  return income * 0.3;
}

// Doesn't copy, but changes original
int CalculateTaxRef(int &income) {
  income = income - 20;  // It changes the original!
  return income * 0.3;
}

// Doesn't change, and doesn't copy
int CalculateTaxConstRef(const int &income) {
  int local_income = income - 20;
  // income = income - 20; // Don't touch my income!

  return local_income * 0.3;
}

int CalculateTaxVector(const std::vector<int> &incomes) {
  //
  int tax = 0;
  for (auto e : incomes) {
    e -= 20;
    tax += e * .30;
  }
  return tax;
}

int main() {
  int income = 2000;
  int tax = CalculateTax(income);

  int x = 1;
  const int y = 1;

  x = 2;
  // y = 2;  // Can't do!

  std::cout << "income: " << income << std::endl;

  tax = CalculateTaxConstRef(income);
  std::cout << "income: " << income << std::endl;

  // std::vector<int> incomes = {1000, 400, 400};
  // auto result = CalculateTaxVector(incomes);
  return 0;
}