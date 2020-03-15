#include "src/lib/graph/pointer.h"
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main() {
  PointerGraph pg;
  pg.CreateSampleGraph1();
  bool result = pg.HasCycle();
  std::cout << "result: " << result << std::endl;
  return 0;
}
