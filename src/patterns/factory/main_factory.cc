
// C++ program to demonstrate factory method design pattern
#include <iostream>
using namespace std;

enum VehicleType { VT_TwoWheeler, VT_ThreeWheeler, VT_FourWheeler };

// Library classes
class Vehicle {
 public:
  virtual void printVehicle() = 0;
  static Vehicle* Create(VehicleType type); // Factory
};
class TwoWheeler : public Vehicle {
 public:
  void printVehicle() { cout << "I am two wheeler" << endl; }
};
class ThreeWheeler : public Vehicle {
 public:
  void printVehicle() { cout << "I am three wheeler" << endl; }
};
class FourWheeler : public Vehicle {
 public:
  void printVehicle() { cout << "I am four wheeler" << endl; }
};

// Factory method to create objects of different types.
// Change is required only in this function to create a new object type
Vehicle* Vehicle::Create(VehicleType type) {
  if (type == VT_TwoWheeler)
    return new TwoWheeler();
  else if (type == VT_ThreeWheeler)
    return new ThreeWheeler();
  else if (type == VT_FourWheeler)
    return new FourWheeler();
  else
    return NULL;
}
//-----------------------------------------------------
// Client class
class Client {
 public:
  // Client doesn't explicitly create objects
  // but passes type to factory method "Create()"
  Client(VehicleType type) {
    pVehicle = Vehicle::Create(type);
  }
  ~Client() {
    if (pVehicle) {
      delete[] pVehicle;
      pVehicle = NULL;
    }
  }
  Vehicle* getVehicle() { return pVehicle; }

 private:
  Vehicle* pVehicle;
};

// Driver program
int main() {
  Client* pClient = new Client(VehicleType::VT_ThreeWheeler);
  Vehicle* pVehicle = pClient->getVehicle();
  pVehicle->printVehicle();
  return 0;
}