template <typename T>
void f(T& param);  // param is a reference

template <typename T>
void g(const T& param);  // param is now a ref-to-const

template <typename T>
void h(T* param);  // param is now a pointer

template <typename T>
void j(T param);  // param is now passed by value

int main(int argc, char const* argv[]) {
  int x = 27;          // as before
  const int cx = x;    // as before
  const int& rx = x;   // as before
  const int* px = &x;  // px is a ptr to x as a const int
  f(x);                // T is int, param's type is int&
  f(cx);               // T is const int,
  // param's type is const int&
  f(rx);  // T is const int,
          // param's type is const int&

  g(x);   // T is int, param's type is const int&
  g(cx);  // T is int, param's type is const int&
  g(rx);  // T is int, param's type is const int&

  h(&x);  // T is int, param's type is int*
  h(px);  // T is const int,
  // param's type is const int*

  j(x);   // T's and param's types are both int
  j(cx);  // T's and param's types are again both int
  j(rx);  // T's and param's types are still both int

  // the constness of ptr
  // will be ignored, and the type deduced for param will be const char*, i.e.,
  // a modifiable pointer to a const character string. The constness of what ptr
  // points to is preserved during type deduction, but the constness of ptr
  // itself is ignored when copying it to create the new pointer, param.
  const char* const ptr =  // ptr is const pointer to const object
      "Fun with pointers";
  j(ptr);  // pass arg of type const char * const

  return 0;
}
