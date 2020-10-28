#include <iostream>

int main() {
  {
    auto myTuple = std::make_tuple(50, "Hello", 10.0);

    std::cout << "std::get<0>(myTuple): " << std::get<0>(myTuple) << std::endl;
    std::cout << "std::get<1>(myTuple): " << std::get<1>(myTuple) << std::endl;
    std::cout << "std::get<2>(myTuple): " << std::get<2>(myTuple) << std::endl;
  }

  {
    auto myTuple = std::make_tuple(1337);
    auto otherTuple = std::make_tuple(std::string("Yo!"));

    auto cat = std::tuple_cat(myTuple, otherTuple);
    std::cout << "std::get<0>(cat): " << std::get<0>(cat) << std::endl;
    std::cout << "std::get<1>(cat): " << std::get<1>(cat) << std::endl;
  }
  return 0;
}
