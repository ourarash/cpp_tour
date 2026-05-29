#include <iostream>
#include <string>
#include <vector>

int main() {
  {
    double d = 3.14159265;
    int i = static_cast<int>(d);
    std::cout << "i: " << i << std::endl;
  }
  {
    int i = 0xabcd;
    char c = (char)(i & 0xFF);
    printf("c:%x\n", c & 0xff);
  }

  {
    int i = 0xabcd;
    char c = (char)(i >> 8);
    printf("c:%x\n", c & 0xff);
  }

  {
    int i = 0xabcd;
    char c = static_cast<char>(i & 0x00ff);
    printf("c3:%x\n", c & 0xff);
  }

  {
    int i = 0xabcd;
    char c = static_cast<char>(i);
    printf("c3:%x\n", c & 0xff);
  }

  // c style casting and increments
  {
    char c = 10;        // 1 byte
    char *char_p = &c;  // 4 bytes

    int *int_p = (int *)(&c);  // 4 bytes

    std::cout << "char_p: " << (long)char_p << std::endl;
    std::cout << "int_p: " << (long)int_p << std::endl;

    *int_p = 12;  //⚡☠️ Dangerous!

    char_p++;
    int_p++;
    std::cout << "char_p: " << (long)char_p << std::endl;
    std::cout << "int_p: " << (long)int_p << std::endl;

    // int *int_p_sc = static_cast<int *>(&c);  // compile-time error

    // ...But we can do this unsafe conversion with reinterpret_cast.
    int *int_p_rp = reinterpret_cast<int *>(&c);
    std::cout << "int_p_rp: " << (long)int_p_rp << std::endl;
  }
}
