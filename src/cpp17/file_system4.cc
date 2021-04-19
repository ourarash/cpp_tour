#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;
int main() {
  fs::path p = fs::path(".") / "src" / ".." / "src";
  std::cout << "Current path is " << fs::current_path() << '\n'
            << "Canonical path for " << p << " is " << fs::canonical(p) << '\n'
            << "weakly Canonical path for " << p << " is "
            << fs::weakly_canonical(p) << '\n';
}