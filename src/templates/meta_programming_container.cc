#include <iostream>
#include <set>
#include <string>
#include <variant>
#include <vector>

#define CONT_SET

#ifdef CONT_SET
#define MYTYPE signed  // selects set.
#else
#define MYTYPE unsigned  // selects vector.
#endif

#define SET signed     // selects set.
#define VECTOR signed  // selects set.

// General case
template <typename T1, typename T2>
class Container {};

// Specialized when T2=unsigned, selects vector.
template <typename T1>
class Container<T1, unsigned> {
 public:
  std::vector<T1> c;
};

// Specialized. When T2=signed, selects set.
template <typename T1>
class Container<T1, signed> {
 public:
  std::set<T1> c;
};

// switch between the container types
//#define CONT_SET

#ifdef CONT_SET
template <typename T>
using container = std::set<T>;
#else
template <typename T>
using container = std::vector<T>;
#endif

int main() {
  // This one uses set or vector depending on CONT_SET
  Container<int, MYTYPE> my_cont;

  // This one uses set
  Container<int, SET> set_cont;

  // This one uses vector
  Container<int, VECTOR> vector_cont;

  container<int> b;
  return 0;
}