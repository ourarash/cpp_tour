template <bool set>
struct boolean {
  static const bool value = set;
};

using true_type = boolean<true>;
using false_type = boolean<false>;
// typedef boolean<true> true_type;

//-----------------------------------------------------
template <typename T>
struct is_char : false_type {};
// is_char::value = false (for everything!)

// Specialized for char
template <>
struct is_char<char> : true_type {};
// is_char::value = true (if it was given char as parameter)
//-----------------------------------------------------
// Note: T has to be a char!
template <typename T>
class A {
  static_assert(is_char<T>::value, "T has to be char");
};
//-----------------------------------------------------
int main() {
  // A<int> a_int;  // Generates compile error 😃
  A<char> a_char;
}
