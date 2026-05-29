
// A design without factory pattern
#include <iostream>
using namespace std;

// Library classes
class Vehicle {
 public:
  virtual void printVehicle() = 0;
};
class TwoWheeler : public Vehicle {
 public:
  void printVehicle() { cout << "I am two wheeler" << endl; }
};
class FourWheeler : public Vehicle {
 public:
  void printVehicle() { cout << "I am four wheeler" << endl; }
};

class FiveWheeler : public Vehicle {
 public:
  void printVehicle() { cout << "I am five wheeler" << endl; }
};

//-----------------------------------------------------
// Client (or user) class
// If we have a new FiveWheeler class, we should also modify the Client.
class Client {
 public:
  Client(int type) {
    // Client explicitly creates classes according to type
    if (type == 1)
      pVehicle = new TwoWheeler();
    else if (type == 2)
      pVehicle = new FourWheeler();
    else if (type == 3)
      pVehicle = new FiveWheeler();
    else
      pVehicle = NULL;
  }

  ~Client() {
    if (pVehicle) {
      delete pVehicle;
      pVehicle = NULL;
    }
  }

  Vehicle *getVehicle() { return pVehicle; }

 private:
  Vehicle *pVehicle;
};

// Driver program
int main() {
  Client *pClient = new Client(1);
  Vehicle *pVehicle = pClient->getVehicle();
  pVehicle->printVehicle();
  return 0;
}