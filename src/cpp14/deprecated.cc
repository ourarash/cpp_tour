#include <iostream>
#include <numeric>
#include <string>
#include <vector>
// Warning: 'old_and_busted' is deprecated
class [[deprecated]] old_and_busted1{};

// Warning: 'old_and_busted' is deprecated: use new_hotness
class [[deprecated("use new_hotness")]] old_and_busted2{};

int main() {
  old_and_busted1 a;
  old_and_busted2 b;

  return 0;
}