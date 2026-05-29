#include <iostream>
#include <string>
#include "src/lib/utility.h"

void BinaryCounter(std::string &counter, int n) {
  for (int i = 0; i < n; i++) {
    int j = counter.size() - 1;

    while (counter[j] == '1') {
      counter[j] = '0';
      j--;
    }

    if (j >= 0) {
      counter[j] = '1';
    }
    std::cout << "counter: " << counter << std::endl;
  }
}

int main() {
  std::string counter = "0000";
  BinaryCounter(counter, 17);

  return 0;
}