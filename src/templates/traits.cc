#include <type_traits>
#include <cstdio>
#include <cinttypes>
 

// Note: T has to be an integral type (int, short, long, ...)
template <typename T>
class MyTest {
  static_assert(std::is_integral<T>::value, "Not an int!");
};

//-----------------------------------------------------
// Note: T has to be either float or integral or enum.
template<typename T>
void Write(T inData, uint32_t inBitCount = sizeof(T) * 8)
{
   static_assert(std::is_arithmetic<T>::value ||
      std::is_enum<T>::value,
      "Generic Write only supports primitive data types" );
  //     WriteBits(&inData, inBitCount);
}

//-----------------------------------------------------

int main() {
  MyTest<int> test_var;
  char b=0;
  Write(b);
  return 0;
}