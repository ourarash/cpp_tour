#include <iostream>
#include <numeric>
#include <string>
#include <vector>
struct Vector3 {
  Vector3(int x1, int y1, int z1) : x(x1), y(y1), z(z1) {}
  int x;
  int y;
  int z;
  [[nodiscard]] static Vector3 Normalize(const Vector3& vec) {
    Vector3 temp = vec;
    // temp.Normalize();
    return temp;
  }
};

int main(int argc, char const* argv[]) {
  Vector3 temp(2, 3, 4);  // Oops, this doesn’t change temp
  Vector3::Normalize(temp);

  return 0;
}
