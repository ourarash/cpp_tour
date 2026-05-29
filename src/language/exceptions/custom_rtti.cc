#include <exception>
#include <iostream>

class TypeInfo {
 public:
  // Takes pointer to super class' type info
  TypeInfo(const TypeInfo* super) : mSuper(super) {}
  // Is this type exactly matching the other pointer?
  bool IsExactly(const TypeInfo* other) const { return (this == other); }
  // Return the super type
  const TypeInfo* SuperType() const { return mSuper; }

 private:
  const TypeInfo* mSuper;
};
//-----------------------------------------------------
// Returns true if ptr is-a Type
// Usage: IsA<Type>(ptr)

template <typename Other, typename This>
bool IsA(const This* ptr) {
  for (const TypeInfo* t = ptr->GetType(); t != nullptr; t = t->SuperType()) {
    if (t->IsExactly(Other::StaticType())) {
      return true;
    }
  }
  return false;
}
//-----------------------------------------------------
// Casts ptr to Type if valid
// Usage: Cast<Type>(ptr)
// dynamic_cast<Type*>(ptr)
template <typename Other, typename This>
Other* Cast(This* ptr) {
  if (IsA<Other>(ptr)) {
    return static_cast<Other*>(ptr);
  } else {
    return nullptr;
  }
}

//-----------------------------------------------------
class Base {
  // Other function

  // End of other functions
  // RTTI
 private:
  static const TypeInfo sType;

 public:
  static const TypeInfo* StaticType() { return &sType; }
  virtual const TypeInfo* GetType() const { return &sType; }
};
const TypeInfo Base::sType(nullptr);
//-----------------------------------------------------
class Derived : public Base {
  // Other function

  // End of other functions

 private:
  static const TypeInfo sType;

 public:
  static const TypeInfo* StaticType() { return &sType; }
  virtual const TypeInfo* GetType() const { return &sType; }
};
const TypeInfo Derived::sType(Base::StaticType());
//-----------------------------------------------------
// With macros
#define DECL_OBJECT()                                    \
 private:                                                \
  static const TypeInfo sType;                           \
                                                         \
 public:                                                 \
  static const TypeInfo* StaticType() { return &sType; } \
  const TypeInfo* GetType() const override { return &sType; }

#define IMPL_OBJECT(d, s) const TypeInfo d::sType(s::StaticType());

class Derived2 : public Base {
  // Other function

  // End of other functions
  DECL_OBJECT();
};

IMPL_OBJECT(Derived2, Base);

int main() {
  Base* base = new Base;
  Base* myBase = new Derived;

  Derived* myDerived = Cast<Derived, Base>(myBase);
  // dynamic_cast returns 0 if not a triangle
  if (myDerived) {
    std::cout << "Yes, it's Derived!" << std::endl;
  }

  Base* myBase2 = Cast<Derived, Base>(base);
  // dynamic_cast returns 0 if not a triangle
  if (myBase2) {
    std::cout << "Yes, myBase2 a triangle!" << std::endl;
  }

  // std::cout << "typeid(*myBase): " << typeid(*myBase).name() << std::endl;
  // std::cout << "typeid(*base): " << typeid(*base).name() << std::endl;

  return 0;
}