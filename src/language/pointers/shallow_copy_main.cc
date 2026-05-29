#include <iostream>

using namespace std;
class Student_shallow {
 public:
  Student_shallow() { id = new int(0); }
  Student_shallow(const Student_shallow& rhs) {
    //
    id = rhs.id;
  }

  Student_shallow &operator=(const Student_shallow& rhs) {
    //
    id = rhs.id;
    return *this;
  }

  ~Student_shallow() {
    delete id;
    id = nullptr;
    cout << "Delete Student_shallow!" << endl;
  }

  int* id;
};

int main() {
  Student_shallow a;
  Student_shallow b = a;
  Student_shallow c;
  c = a;
  cout << *a.id << *b.id << *c.id << endl;
  *(c.id) = 1;
  cout << *a.id << *b.id << *c.id << endl;
}