#include <iostream>
#include <string>

struct Person {
  std::string first_name;
  std::string last_name;
  int age;

  Person() { std::cout << "Person constructor" << std::endl; }
  ~Person() { std::cout << "Person destructor" << std::endl; }
  std::string FullName() { return first_name + ' ' + last_name; }
};

template <typename T>
class UniquePtr {
 public:
  // Construct based on pointer to dynamic object
  explicit UniquePtr(T* obj) : mObj(obj) {}

  // Destructor (clean up memory)
  ~UniquePtr() {
    // Delete dynamically allocated object
    std::cout << "Deleting the pointer." << std::endl;
    delete mObj;
  }

  // Overload dereferencing * and ->
  T& operator*() { return *mObj; }
  T* operator->() { return mObj; }

 private:
  // Disallow assignment/copy
  UniquePtr(const UniquePtr& other);
  UniquePtr& operator=(const UniquePtr& other);

  // Track the dynamically allocated object
  T* mObj;
};

int main() {
  {  // Construct a scoped pointer to a newly-allocated object
    UniquePtr<Person> p1(new Person());

    // Can call functions just like a regular pointer!
    p1->first_name = "Ari";
    p1->last_name = "Saif";

    std::cout << "p1->FullName(): " << p1->FullName() << std::endl;

    // No delete necessary :)
  }

  std::cout << "------------------------------------------" << std::endl;


  // Copy and references
  {
    UniquePtr<Person> p1(new Person());

    p1->first_name = "Ari";
    p1->last_name = "Saif";

    std::cout << "p1->FullName(): " << p1->FullName() << std::endl;

    // Copy is not possible!
    // UniquePtr<Person> p2 = p1;

    // Can have a reference to it.
    UniquePtr<Person>& p3 = p1;
    std::cout << "p3->FullName(): " << p3->FullName() << std::endl;
  }
  return 0;
}

