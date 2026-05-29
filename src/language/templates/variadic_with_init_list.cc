// Effective modern C++ Item 7
#include <iostream>

#include <vector>
template <typename T,      // type of object to create
          typename... Ts>  // types of arguments to use
void doSomeWork(Ts &&... params) {
  // create local T object from params...

  T localObject1(std::forward<Ts>(params)...);  // using parens
  T localObject2{std::forward<Ts>(params)...};  // using braces
}

int main(int argc, char const *argv[]) {
  std::vector<int> v;
  doSomeWork<std::vector<int>>(10, 20);

  return 0;
}
