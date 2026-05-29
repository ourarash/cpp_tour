#include <iostream>
#include <string>

struct Person {
  std::string first_name;
  std::string last_name;
  int age;

  Person() { std::cout << "Person constructor" << std::endl; }
  ~Person() { std::cout << "Person destructor" << std::endl; }
  void Talk() { std::cout << "Hi, my name is: " << FullName() << std::endl; }

  std::string FullName() { return first_name + ' ' + last_name; }
};
//-----------------------------------------------------
// Declare the control block
struct ControlBlock {
  unsigned mShared;
  unsigned mWeakShared;
};
//-----------------------------------------------------s
template <typename T>
class WeakPtr;

//-----------------------------------------------------
template <typename T>
class SharedPtr {
 public:
  // friend class WeakPtr;

  // Construct based on pointer to dynamic object
  explicit SharedPtr(T* obj) : mObj(obj) {
    // Dynamically allocate a new control block
    mBlock = new ControlBlock;
    // Initially, one reference (self)
    mBlock->mShared = 1;
    // No weak references to start
    mBlock->mWeakShared = 0;
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
      delete mObj;
      if (mBlock->mWeakShared == 0) {
        delete mBlock;
      }
    }

    std::cout << "mBlock->mShared: " << mBlock->mShared << std::endl;
    std::cout << "mBlock->mWeakShared: " << mBlock->mWeakShared << std::endl;
  }
  // Overload dereferencing * and ->
  T& operator*() { return *mObj; }
  T* operator->() { return mObj; }

  void PrintBlock() {
    std::cout << "mBlock->mShared: " << mBlock->mShared
              << ", mBlock->mWeakShared: " << mBlock->mWeakShared << std::endl;
  }

  friend class WeakPtr<T>;

 private:
  // Disallow assignment (for simplicity)
  SharedPtr& operator=(const SharedPtr& other);
  // Pointer to dynamically allocated object
  T* mObj;
  // Pointer to control block
  ControlBlock* mBlock;
};
//-----------------------------------------------------
template <typename T>
class WeakPtr {
 public:
  // Constructor accepts SharedPtr
  explicit WeakPtr(SharedPtr<T>& refPtr) {
    // Copy object/block from SharedPtr
    mObj = refPtr.mObj;
    mBlock = refPtr.mBlock;

    // Increment weak reference count
    mBlock->mWeakShared += 1;
  }

  explicit WeakPtr() {}

  // Allow copy constructor
  WeakPtr(const WeakPtr& other) {
    mObj = other.mObj;
    mBlock = other.mBlock;

    // Increment weak reference count
    mBlock->mWeakShared += 1;
  }
  // Destructor
  ~WeakPtr() {
    std::cout << "WeakPtr desctructor." << std::endl;

    // Decrement weak reference count
    mBlock->mWeakShared -= 1;

    // If both strong and weak references are 0,
    // delete control block
    if (mBlock->mShared == 0 && mBlock->mWeakShared == 0) {
      delete mBlock;
    }
    std::cout << "mBlock->mShared: " << mBlock->mShared << std::endl;
    std::cout << "mBlock->mWeakShared: " << mBlock->mWeakShared << std::endl;
  }

  bool isAlive() {
    // Only alive if strong ref count is not 0
    // (Because if it hits 0, object is destroyed)
    return (mBlock->mShared != 0);
  }

  // Overload dereferencing * and ->
  T& operator*() {
    if (!isAlive()) {
      throw std::exception();
    }
    return *mObj;
  }

  T* operator->() {
    if (!isAlive()) {
      throw std::exception();
    }
    return mObj;
  }

  void PrintBlock() {
    std::cout << "mBlock->mShared: " << mBlock->mShared
              << ", mBlock->mWeakShared: " << mBlock->mWeakShared << std::endl;
  }

 private:
  // Disallow assignment (for simplicity)
  WeakPtr& operator=(const WeakPtr& other);
  // Pointer to dynamically allocated object
  T* mObj;
  // Pointer to control block
  ControlBlock* mBlock;
};

WeakPtr<Person> MakeWeakPerson() {
  // Construct a SharedPtr
  SharedPtr<Person> myPerson(new Person());
  myPerson->first_name = "Ari";
  myPerson->last_name = "Saif";

  WeakPtr<Person> weakPerson(myPerson);

  std::cout << "weakPerson->FullName(): " << weakPerson->FullName()
            << std::endl;

  // Return a WeakPtr to the Person
  return weakPerson;
}

int main() {
  // Weak pointer going out of scope before shared pointer
  {
    SharedPtr<Person> p_shared1(new Person());

    // Can call functions just like a regular pointer!
    p_shared1->first_name = "Ari";
    p_shared1->last_name = "Saif";

    std::cout << "p_shared1->FullName(): " << p_shared1->FullName()
              << std::endl;

    p_shared1.PrintBlock();

    SharedPtr<Person> p_shared2 = p_shared1;

    p_shared2->first_name = "ari";

    std::cout << "p_shared1->FullName(): " << p_shared1->FullName()
              << std::endl;

    p_shared1.PrintBlock();
    p_shared2.PrintBlock();

    {
      WeakPtr<Person> weakPtr(p_shared1);
      std::cout << "weakPtr->FullName(): " << weakPtr->FullName() << std::endl;
      p_shared2.PrintBlock();
    }

    std::cout << "p_shared1->FullName(): " << p_shared1->FullName()
              << std::endl;
  }

  std::cout << "------------------------------------------" << std::endl;
  // Shared pointer going out of scope before weak pointer

  // shared ====> obj
  // weak ====> obj
  {
    WeakPtr<Person> weakPtr(MakeWeakPerson());

    // Try to access weak reference here
    std::cout << "weakPtr->FullName(): " << weakPtr->FullName() << std::endl;
  }
  return 0;
}
