#include <iostream>
template <class T>
class Singleton {
 private:
  static T* sInstance;

 protected:
  Singleton() {}

 public:
  static T& get() {
    if (sInstance) {
      std::cout << "Reusing the instance." << std::endl;
      return *sInstance;
    } else {
      std::cout << "Constructing the instance." << std::endl;
      sInstance = new T();
      return *sInstance;
    }
  }
};

// Initialize the static variable.
template <class T>
T* Singleton<T>::sInstance = nullptr;

class MyFileSystem : public Singleton<MyFileSystem> {
 public:
  void Print() { std::cout << "This is my file system!" << std::endl; }
};

int main(int argc, char const* argv[]) {
  MyFileSystem::get().Print();
  
  MyFileSystem::get().Print();
  MyFileSystem::get().Print();
  MyFileSystem::get().Print();

  return 0;
}
