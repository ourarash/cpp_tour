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

template <class T>
T* Singleton<T>::sInstance = 0;

// class FileSystem : public Singleton<FileSystem>
