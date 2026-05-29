#include <iostream>
#include <string>
template <class T>
class NamedObject {
 public:
  // this ctor no longer takes a const name, because nameValue
  // is now a reference-to-non-const string. The char* constructor
  // is gone, because we must have a string to refer to.
  NamedObject(std::string& name, const T& value)
      : nameValue(name), objectValue(value) {}
  // as above, assume no
  // operator= is declared
  //  private:
  std::string& nameValue;  // this is now a reference
  const T objectValue;     // this is now const
};
int main(int argc, char const* argv[]) {
  std::string newDog("Persephone");
  std::string oldDog("Satch");
  NamedObject<int> p(newDog, 2);
  NamedObject<int> s(oldDog, 36);

  std::cout << "p.nameValue: " << p.nameValue << std::endl;
  std::cout << "s.nameValue: " << s.nameValue << std::endl;

  newDog = "test";
  std::cout << "p.nameValue: " << p.nameValue << std::endl;

  // p = s;  // ---> Doesn't compile because the class has reference member
  // variables
  return 0;
}
