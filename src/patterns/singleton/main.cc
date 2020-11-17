template <class T>
class Singleton {
 private:
  static T* sInstance;

 protected:
  Singleton() {}

 public:
  static T& get() {
    if (sInstance) {
      return *sInstance;
    } else {
      sInstance = new T();
      return *sInstance;
    }
  }
};

// Initialize the static variable.
template <class T>
T* Singleton<T>::sInstance = nullptr;


class MyFileSystem : public Singleton<FileSystem>{

};
MyFileSystem::get()