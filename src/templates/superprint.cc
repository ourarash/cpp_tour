#include <iostream>
#include <type_traits>
#include <vector>

template <bool set>
struct boolean {
  static const bool value = set;
};

using true_type = boolean<true>;
using false_type = boolean<false>;
//-----------------------------------------------------
template <typename T1, typename T2>
struct is_same : false_type {};

// Specialization
template <typename T>
struct is_same<T, T> : true_type {};
//-----------------------------------------------------
template <typename T>
struct has_iterator {
  template <typename U>
  static false_type check(...);

  template <typename U>
  static true_type check(typename U::iterator*);

  // static const bool value =
  //     is_same<decltype(check<T>(nullptr)), true_type>::value;

  static const bool value = decltype(check<T>(nullptr))::value;
};
//-----------------------------------------------------
template <typename T>
typename std::enable_if<!has_iterator<T>::value, void>::type superPrint(
    const T& t) {
  std::cout << t << std::endl;
}
//-----------------------------------------------------
template <typename T>
typename std::enable_if<has_iterator<T>::value, void>::type superPrint(
    const T& t) {
  bool printComma = false;
  for (auto i : t) {
    if (!printComma) {
      printComma = true;
    } else {
      std::cout << ',';
    }
    std::cout << i;
  }
  std::cout << std::endl;
}
//-----------------------------------------------------
int main(int argc, char const* argv[]) {
  std::vector<int> my_vector = {1, 2, 3, 4, 5};
  superPrint(5);
  superPrint(my_vector);
  return 0;
}
