#include <iostream>


using namespace std;
class Student_deep {
 public:
 
  Student_deep() { id = new int(0); }
  Student_deep(const Student_deep& rhs) {
    //
    id = new int(*(rhs.id));
  }

  Student_deep& operator=(const Student_deep& rhs) {
    //
    id = new int(*(rhs.id));
    return *this;
  }
  ~Student_deep() {
    delete id;
    id = nullptr;
    cout << "Delete Student_deep!" << endl;
  }

  int* id;
};

int main() {
  Student_deep a;
  Student_deep b = a;
  Student_deep c;
  c = a;
  cout << *a.id << *b.id << *c.id << endl;
  *c.id = 1;
  cout << *a.id << *b.id << *c.id << endl;
}