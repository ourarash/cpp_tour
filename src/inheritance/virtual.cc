#include <iostream>
struct Animal {
  virtual ~Animal() = default;
  virtual void Eat() { std::cout << "Animal Eat" << std::endl; }
};

struct Mammal : virtual Animal {
  virtual void Breathe() {}
};

struct WingedAnimal : virtual Animal {
  virtual void Flap() {}
};

// A bat is a winged mammal
struct Bat : Mammal, WingedAnimal {};

int main() {
  {
    Bat bat;
    bat.Eat();  // Won't compile unless virtual inheritance.
  }

  {
    Bat bat;
    Animal& a = bat;  // Won't compile unless virtual inheritance.
  }

  {
    // Compile without virtual inheritance.
    Bat b;
    Animal& mammal = static_cast<Mammal&>(b);
    mammal.Eat();
    Animal& winged = static_cast<WingedAnimal&>(b);
    winged.Eat();
  }

  return 0;
}