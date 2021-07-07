#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>
std::tuple<int, char, short> f() { return std::make_tuple(1, 'a', 3); }

int main(int argc, char const *argv[]) {
  {
    auto [x, y, z] = f();  // types are: T1, T2, T3
    std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
  }

  {
    auto [x, y, z] = f();  // types are: T1, T2, T3
    std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
  }

  // {
  //   int x;
  //   char y;
  //   float z;
  //   auto res = f();  // types are: T1, T2, T3
  //   x = std::get<0>(res);
  //   y = std::get<1>(res);
  //   std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
  // }
  std::cout << "------------------------------------------" << std::endl;
  {
    std::map<int, std::string> m;
    m[1] = "hi";
    m[2] = "bye";
    for (auto &e : m) {
      auto key = e.first;
      auto value = e.second;
    }
    for (auto [key, val] : m) {
      std::cout << "key: " << key << ", val: " << val << std::endl;
    }
  }
  std::cout << "------------------------------------------" << std::endl;
  {
    std::map<int, std::string> mymap;
    // types are: iterator, bool
    auto [iter, success] = mymap.insert(std::make_pair(1, "hi"));

    std::cout << "success: " << success << std::endl;
  }
  {
    struct mystruct {
      int i;
      std::string s;
      double d;
    };
    mystruct s = {1, "xyzzy", 3.14};
    auto [x, y, z] = s;  // types are: int, string, double

    std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
  }
  return 0;
}
