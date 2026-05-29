#include <iostream>
#include <string>
#include <vector>

class Widget {};

auto loggingDel = [](Widget *pw)  // custom deleter
{                                 // (as in Item 18)
  // makeLogEntry(pw);
  delete pw;
};
std::unique_ptr<                  // deleter type is
    Widget, decltype(loggingDel)  // part of ptr type
    >
    upw(new Widget, loggingDel);

std::shared_ptr<Widget>           // deleter type is not
    spw(new Widget, loggingDel);  // part of ptr type

int main(int argc, char const *argv[]) {
  auto customDeleter1 = [](Widget *pw) {};  // custom deleters,
  auto customDeleter2 = [](Widget *pw) {};  // each with a
  // different type
  std::shared_ptr<Widget> pw1(new Widget, customDeleter1);
  std::shared_ptr<Widget> pw2(new Widget, customDeleter2);

  //   Because pw1 and pw2 have the same type, they can be placed in a container
  //   of objects
  // of that type
  std::vector<std::shared_ptr<Widget>> vpw{pw1, pw2};
  return 0;
}
