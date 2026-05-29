#include <functional>
#include <iostream>
#include <list>
#include <string>
#include <vector>

class Subject;

class Observer {
 public:
  virtual ~Observer() = default;
  virtual void Update(Subject* updatedSubject) = 0;
};

class Subject {
 public:
  virtual ~Subject() = default;

  // Register and unregister.
  virtual void Attach(Observer* o) { mObservers.push_back(o); }
  virtual void Detach(Observer* o) { mObservers.remove(o); }

  virtual void NotifyObservers() {
    for (auto i = mObservers.begin(); i != mObservers.end(); ++i) {
      (*i)->Update(this);
    }
  }

 private:
  std::list<Observer*> mObservers;
  // Alternative: store callbacks instead of Observer pointers.
  std::list<std::function<void(Subject*)>> mLambdaList;
};

class MyObserver : public Observer {
 public:
  void Update(Subject* /*updatedSubject*/) override {
    std::cout << "I got updated!" << std::endl;
  }
};

class mySubject : public Subject {
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
