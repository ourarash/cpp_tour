#include <iostream>
#include <string>

struct Person {
  std::string first_name;
  std::string last_name;
  int age;

  Person() { std::cout << "Person constructor" << std::endl; }
  void Talk() { std::cout << "Hi, my name is: " << FullName() << std::endl; }

  std::string FullName() { return first_name + ' ' + last_name; }
};

// Declare the control block
struct ControlBlock {
  unsigned mShared;  // Just a counter
};

template <typename T>
class SharedPtr {
 public:
  // Construct based on pointer to dynamic object
  explicit SharedPtr(T* obj) : mObj(obj) {
    // Dynamically allocate a new control block
    mBlock = new ControlBlock;
    // Initially, one reference (self)
    mBlock->mShared = 1;
  }

  // Allow copy constructor
  SharedPtr(const SharedPtr& other) {
    // Grab object and control block from other
    mObj = other.mObj;
    mBlock = other.mBlock;

    // Increment ref count
    mBlock->mShared += 1;
  }

  // Destructor (reduce ref count)
  ~SharedPtr() {
    std::cout << "Shared pointer desctructor." << std::endl;

    // Decrement ref count
    mBlock->mShared -= 1;

    // If there are zero references, delete the object
    // and the control block
    if (mBlock->mShared == 0) {
      std::cout << "Deleting the pointer." << std::endl;

      delete mObj;
      delete mBlock;
    }
  }
  // Overload dereferencing * and ->
  T& operator*() { return *mObj; }
  T* operator->() { return mObj; }

 private:
  // Disallow assignment (for simplicity)
  SharedPtr& operator=(const SharedPtr& other);
  // Pointer to dynamically allocated object
  T* mObj;
  // Pointer to control block
  ControlBlock* mBlock;
};

void DoStuff(SharedPtr<Person> p) { p->Talk(); }

void DoStuff2(SharedPtr<Person>& p) { p->Talk(); }

void DoStuff(Person *p) { p->Talk(); }

int main() {
  {  // Construct a scoped pointer to a newly-allocated object
    SharedPtr<Person> p1(new Person());

    // Can call functions just like a regular pointer!
    p1->first_name = "Ari";
    p1->last_name = "Saif";

    std::cout << "p1->FullName(): " << p1->FullName() << std::endl;

    // No delete necessary :)
  }

  std::cout << "------------------------------------------" << std::endl;

  // Copy and references
  {
    SharedPtr<Person> p1(new Person());

    p1->first_name = "Ari";
    p1->last_name = "Saif";

    p1->Talk();

    // Copy is possible!
    {
      SharedPtr<Person> p2 = p1;
      p2->Talk();
    }

    // Can have a reference to it.
    SharedPtr<Person>& p3 = p1;
    std::cout << "p3->FullName(): " << p3->FullName() << std::endl;
  }
  std::cout << "------------------------------------------" << std::endl;
  // Passing to function
  {  // Construct a scoped pointer to a newly-allocated object
    SharedPtr<Person> p1(new Person());

    // Can call functions just like a regular pointer!
    p1->first_name = "Ari";
    p1->last_name = "Saif";

    DoStuff(p1);

    // No delete necessary :)
  }
  return 0;
}
