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
// Note: T1 and T2 should be the same!
template <typename T1, typename T2>
class A {
  static_assert(is_same<T1, T2>::value, "T1 and T2 have to be the same!");
};

//-----------------------------------------------------
int main() {
  A<char, char> a_char_char;  // Ok
  // A<char, int> a_char_int;    // Generates compile error 😃
}
