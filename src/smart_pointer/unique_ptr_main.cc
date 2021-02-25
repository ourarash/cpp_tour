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

  // Move constructor
  UniquePtr(UniquePtr&& other) {
    mObj = std::move(other.mObj);
    other.mObj = nullptr;
  }

  // Move assignment
  UniquePtr& operator=(UniquePtr&& other) {
    mObj = std::move(other.mObj);
    other.mObj = nullptr;
    return *this;
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

void DoStuff(UniquePtr<Person> p) { p->Talk(); }
void DoStuff3(UniquePtr<Person>& p) { p->Talk(); }

UniquePtr<Person> DoStuff2(UniquePtr<Person> p) {
  p->Talk();
  return std::move(p);
}

int main() {
  {  // Construct a scoped pointer to a newly-allocated object
    UniquePtr<Person> p1(new Person());

    // Can call functions just like a regular pointer!
    p1->first_name = "Ari";
    p1->last_name = "Saif";

    p1->Talk();

    // UniquePtr<Person> p2 = p1;
    // DoStuff(p1);

    // UniquePtr<Person> p3;
    // p3 = p1;
    // No delete necessary :)
  }

  std::cout << "------------------------------------------" << std::endl;

  // Copy and references
  {
    UniquePtr<Person> p1(new Person());

    p1->first_name = "Ari";
    p1->last_name = "Saif";

    p1->Talk();

    // Copy is not possible!
    // UniquePtr<Person> p2 = p1;

    // Can have a reference to it.
    UniquePtr<Person>& p3 = p1;
    p3->Talk();

    DoStuff3(p1);
  }
  std::cout << "------------------------------------------" << std::endl;

  {  // Construct a scoped pointer to a newly-allocated object
    UniquePtr<Person> p1(new Person());

    // Can call functions just like a regular pointer!
    p1->first_name = "Ari";
    p1->last_name = "Saif";

    DoStuff(std::move(p1));

    UniquePtr<Person> p3 = std::move(p1);

    // p1->Talk();  // Don't do this, it crashes!
  }

  std::cout << "------------------------------------------" << std::endl;

  {  // Construct a scoped pointer to a newly-allocated object
    UniquePtr<Person> p1(new Person());

    // Can call functions just like a regular pointer!
    p1->first_name = "Ari";
    p1->last_name = "Saif";

    p1 = DoStuff2(std::move(p1));

    p1->Talk();  // Don't do this, it crashes!
  }

  return 0;
}

{
  
  int* p1 = new int;   // counter = 1
  {
    int* p2 = p1;      // counter = 2
    { 
      int* p3 = p1;  // counter = 3
    }
    // counter = 2
  }
  // counter = 1

  std::cout << "*p1: " << *p1 << std::endl;
 
}
// counter = 0