template <bool set>
struct boolean {
  static const bool value = set;
};

using true_type = boolean<true>;
using false_type = boolean<false>;
//-----------------------------------------------------
// Note: T should only be unsigned:
// unsigned char
// unsigned int
// unsigned long
// unsigned long long
// unsigned short
template <typename T>
struct is_unsigned : false_type {};

// Specialized
template <>
struct is_unsigned<unsigned char> : true_type {};

template <>
struct is_unsigned<unsigned int> : true_type {};

template <>
struct is_unsigned<unsigned short> : true_type {};

template <>
struct is_unsigned<unsigned long> : true_type {};

template <>
struct is_unsigned<unsigned long long> : true_type {};
//-----------------------------------------------------
template <typename T>
class A {
  static_assert(is_unsigned<T>::value, "T has to be unsigned!");
};
//-----------------------------------------------------
int main() {
  // A<int> a_int;  // Generates compile error :)
  A<unsigned int> a_uint;
}
