#include <iostream>
#include <string>
class TextBlock {
 public:
  TextBlock(const std::string& s) : text(s) {}
  const char& operator[](std::size_t position) const  // operator[] for
  {
    return text[position];
  }                                       // const objects
  char& operator[](std::size_t position)  // operator[] for
  {
    return
        // cast away const on
        // op[]'s return type;
        // add const to *this's type;
        // call const version of op[]
        const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);
  }  // non-const objects
 private:
  std::string text;
};

int main(int argc, char const* argv[]) {
  TextBlock tb("Hello");
  // calls non-const
  // TextBlock::operator[]
  std::cout << "tb[0]: " << tb[0] << std::endl;
  tb[0] = 'x';
  std::cout << "tb[0]: " << tb[0] << std::endl;

  const TextBlock ctb("World");
  // calls const TextBlock::operator[]
  std::cout << "ctb[0]: " << ctb[0] << std::endl;
  // ctb[0] = 'x';// compile error

  // char* p = &ctb[0];  // compile error
  std::cout << "ctb[0]: " << ctb[0] << std::endl;

  return 0;
}
