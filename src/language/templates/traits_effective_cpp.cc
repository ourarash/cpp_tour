// Effective C++, Item 47
#include <iterator>
#include <stdexcept>

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};
template <typename T>  // template params elided
class deque {
  deque() {}

 public:
  class iterator {
   public:
    typedef random_access_iterator_tag iterator_category;
  };
};

template <typename T>
class list {
 public:
  class iterator {
   public:
    typedef bidirectional_iterator_tag iterator_category;
  };
};

// the iterator_category for type IterT is whatever IterT says it is;
// see Item 42 for info on the use of "typedef typename"
template <typename IterT>
struct iterator_traits {
  typedef typename IterT::iterator_category iterator_category;
};

template <typename IterT>       // partial template specialization
struct iterator_traits<IterT*>  // for built-in pointer types
{
  typedef random_access_iterator_tag iterator_category;
};

//-----------------------------------------------------------------------------
template <typename IterT, typename DistT>   // use this impl for
void doAdvance(IterT& iter, DistT d,        // random access
               random_access_iterator_tag)  // iterators
{
  // iter += d;
}
template <typename IterT, typename DistT>   // use this impl for
void doAdvance(IterT& iter, DistT d,        // bidirectional
               bidirectional_iterator_tag)  // iterators
{
  if (d >= 0) {
    while (d--) ++iter;
  } else {
    while (d++) --iter;
  }
}
template <typename IterT, typename DistT>  // use this impl for
void doAdvance(IterT& iter, DistT d,       // input iterators
               input_iterator_tag) {
  if (d < 0) {
    // throw out_of_range("Negative distance");  // see below
  }
  while (d--) ++iter;
}

template <typename IterT, typename DistT>
void advance(IterT& iter, DistT d) {
  doAdvance(    // call the version
      iter, d,  // of doAdvance

      // passing an extra object of the
      // appropriate iterator category type so that the compiler will use
      // overloading resolution to call the proper implementation
      typename                                     // that is
      iterator_traits<IterT>::iterator_category()  // appropriate for
  );                                               // iter's iterator
}

int main(int argc, char const* argv[]) {
  deque<int>::iterator dIter;
  advance<deque<int>::iterator, int>(dIter, 5);

  return 0;
}
