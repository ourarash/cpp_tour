#include <functional>
#include <iostream>
#include <vector>

template <typename T>
T Add(T var1, T var2) {
  return var1 + var2;
}

template <typename T>
T Max(T var1, T var2) {
  return std::max(var1, var2);
}

template <typename T>
struct Node {
  T value;
  int l;
  int r;
};

template <typename T>
class SegmentTree {
  struct SegmentIndices {
    int left;
    int right;
  };

 public:
  SegmentTree(std::vector<T> &inputs) { elements.resize(inputs.size() * 4); }
  // Builds segment tree for members of inputs from l to r rooted at
  // elements[index].
  void build(std::vector<T> &inputs, int index, int l, int r,
             std::function<T(T, T)> func = Add<T>) {
    if (l == r) {
      elements[index].value = inputs[l];
      elements[index].l = elements[index].r = l;
    } else {
      int m = (l + r) / 2;

      auto [left_child_index, right_child_index] = GetChildrenIndices(index);

      build(inputs, left_child_index, l, m, func);
      build(inputs, right_child_index, m + 1, r, func);

      elements[index].value = func(elements[left_child_index].value,
                                   elements[right_child_index].value);

      elements[index].l = l;
      elements[index].r = r;
    }
  }

  SegmentIndices GetChildrenIndices(int index) {
    SegmentIndices result;
    result.left = index * 2 + 1;
    result.right = index * 2 + 2;
    return result;
  }

  /**
   * Queries in the range [l, r]
   * The current index, tl, and tr are given.
   * initial_value: the value of the query if the segment is empty.
   */
  T query(int index, int tl, int tr, int l, int r, int initial_value = 0,
          std::function<T(T, T)> func = Add<T>) {
    if (l > r) {
      return initial_value;
    }

    if (l == tl && r == tr) {
      return elements[index].value;
    }

    auto [left_child_index, right_child_index] = GetChildrenIndices(index);

    int m = (tl + tr) / 2;

    auto left =
        query(left_child_index, tl, m, l, std::min(m, r), initial_value, func);

    auto right = query(right_child_index, m + 1, tr, std::max(l, m + 1), r,
                       initial_value, func);

    return func(left, right);
  }

  void update(int index, int tl, int tr, int pos, int new_val,
              std::function<T(T, T)> func = Add<T>) {
    if (tl == tr) {
      elements[index].value = new_val;
    } else {
      int tm = (tl + tr) / 2;
      auto [left_child_index, right_child_index] = GetChildrenIndices(index);

      if (pos <= tm) {
        update(left_child_index, tl, tm, pos, new_val, func);
      } else {
        update(right_child_index, tm + 1, tr, pos, new_val, func);
      }
      elements[index] =
          func(elements[left_child_index], elements[right_child_index]);
    }
  }

  std::vector<Node<T>> elements;
};