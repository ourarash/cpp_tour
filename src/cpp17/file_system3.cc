
#include <cassert>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
  fs::path p5 = "/usr/a/b/c";
  fs::path p6 = "/usr/a/b/c";
  assert(p5 == p6);
  assert(p5.compare(p6) == 0);

  p5 = "/usr/a/b/c";
  p6 = "/usr/a/b/c/d";
  assert(p5 < p6);
  assert(p5.compare(p6) < 0);
}