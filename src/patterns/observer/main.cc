#include <iostream>
#include <list>
#include <string>
#include <vector>
class Subject;
//-----------------------------------------------------
class Observer {
 public:
  virtual void Update(Subject* updatedSubject) = 0;
};
//-----------------------------------------------------s
class Subject {
 public:
  // Register, and unregister
  virtual void Attach(Observer* o) { mObservers.push_back(o); }  // subscribe
  virtual void Detach(Observer* o) { mObservers.remove(o); }     // unsubscribe

  virtual void NotifyObservers() {
    for (auto i = mObservers.begin(); i != mObservers.end(); ++i) {
      i->Update(this);
    }
  }

 private:
  std::list<Observer*> mObservers;
  std::list<std::function<>> mLambdaList; // An Alternative
};

class MyObserver : Observer {
 public:
  void Update(Subject* updatedSubject) {
    std::cout << "I got updated!" << std::endl;
  };
};

class mySubject : Subject {
 public:
  void Assign(int value) {
    mValue = value;
    NotifyObservers();
  }
  int mValue;
};

int main(int argc, char const* argv[]) {
  MyObserver a, b;
  mySubject subject;
  subject.Attach(&a);
  subject.Attach(&b);

  subject.Assign(565);

  return 0;
}
