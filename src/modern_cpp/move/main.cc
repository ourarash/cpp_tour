#include <iostream>
#include <vector>

// A class with a member function that returns a reference
class IntWrapper {
 public:
  IntWrapper(int i) : i_(i) {}
  int GetI() { return i_; }

  int &GetIReference() {
    int &result = i_;
    return result;
  }
  int i_;
};

int main() {
  {
    // Store the returned lvalue into a reference.
    {
      IntWrapper int_wrapper(1);
      std::cout << "int_wrapper.GetI(): " << int_wrapper.GetI() << std::endl;

      int val = int_wrapper.GetIReference();
      val++;
      std::cout << "int_wrapper.GetI(): " << int_wrapper.GetI() << std::endl;
      std::cout << "val: " << val << std::endl;
    }

    // Store the returned lvalue into a reference.
    {
      IntWrapper int_wrapper(1);
      std::cout << "int_wrapper.GetI(): " << int_wrapper.GetI() << std::endl;

      int &ref = int_wrapper.GetIReference();
      ref++;
      std::cout << "int_wrapper.GetI(): " << int_wrapper.GetI() << std::endl;
      std::cout << "ref: " << ref << std::endl;
    }

    // Directly use the returned lvalue
    {
      IntWrapper int_wrapper(1);

      int_wrapper.GetIReference()++;
      std::cout << "int_wrapper.GetI(): " << int_wrapper.GetI() << std::endl;

      ++int_wrapper.GetIReference();
      std::cout << "int_wrapper.GetI(): " << int_wrapper.GetI() << std::endl;
    }

    // Pointer to returned lvalue
    {
      IntWrapper int_wrapper(1);

      int *ptr_lvalue = &int_wrapper.GetIReference();
      (*ptr_lvalue)++;
      std::cout << "int_wrapper.GetI(): " << int_wrapper.GetI() << std::endl;
    }

    // Pointer to returned rvalue
    {
      IntWrapper int_wrapper(1);
      // int *ptr_rvalue = &int_wrapper.GetI();  // Invalid

      // (*ptr_rvalue)++;
      std::cout << "int_wrapper.GetI(): " << int_wrapper.GetI() << std::endl;
    }
  }

  return 0;
}