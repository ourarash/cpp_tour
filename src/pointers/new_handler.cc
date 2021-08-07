#include <iostream>
#include <string>
class Widget {
 public:
  static std::new_handler set_new_handler(std::new_handler p) noexcept;
  static void* operator new(std::size_t size) noexcept;

 private:
  static std::new_handler currentHandler;
};

std::new_handler Widget::currentHandler = 0;  // init to null in the class
// impl. file

std::new_handler Widget::set_new_handler(std::new_handler p) noexcept {
  std::new_handler oldHandler = currentHandler;
  currentHandler = p;
  return oldHandler;
}

class NewHandlerHolder {
 public:
  explicit NewHandlerHolder(std::new_handler nh)  // acquire current
      : handler(nh) {}                            // new-handler

  ~NewHandlerHolder()  // release it
  {
    std::set_new_handler(handler);
  }

 private:
  std::new_handler handler;                   // remember it
  NewHandlerHolder(const NewHandlerHolder&);  // prevent copying
  NewHandlerHolder&                           // (see Item 14)
  operator=(const NewHandlerHolder&);
};

void* Widget::operator new(std::size_t size) noexcept {
  NewHandlerHolder                              // install Widget's
      h(std::set_new_handler(currentHandler));  // new-handler
  return ::operator new(size);                  // allocate memory
  // or throw
}  // restore global
// new-handler

template <typename T>      // "mixin-style" base class for
class NewHandlerSupport {  // class-specific set_new_handler
 public:                   // support
  static std::new_handler set_new_handler(std::new_handler p) noexcept;
  static void* operator new(std::size_t size);
  // other versions of op. new 􀬛
  // see Item 52
 private:
  static std::new_handler currentHandler;
};

template <typename T>
std::new_handler NewHandlerSupport<T>::set_new_handler(
    std::new_handler p) throw() {
  std::new_handler oldHandler = currentHandler;
  currentHandler = p;
  return oldHandler;
}
template <typename T>
void* NewHandlerSupport<T>::operator new(std::size_t size) {
  NewHandlerHolder h(std::set_new_handler(currentHandler));
  return ::operator new(size);
}
// this initializes each currentHandler to null
template <typename T>
std::new_handler NewHandlerSupport<T>::currentHandler = 0;