
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
class Client {
 public:
  Client(int type) {
    // Client explicitly creates classes according to type
    if (type == 1)
      pVehicle = new TwoWheeler();
    else if (type == 2)
      pVehicle = new FourWheeler();
    else
      pVehicle = NULL;
  }

  ~Client() {
    if (pVehicle) {
      delete[] pVehicle;
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


H --> Font_h; // 100 bytes
E --> Font_e; // 100 bytes
L --> Font_l; // 100 bytes
L --> Font_l; // 100 bytes



H --> 48; // 1 byte
E --> 45; // 1 byte
L --> 4C; // 1 byte
L --> 4C; // 1 byte


ASCII: maps an integer to an image