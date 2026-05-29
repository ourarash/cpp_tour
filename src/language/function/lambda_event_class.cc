#include <iostream>
#include <numeric>
#include <vector>

class Event {
 public:
  // Add a handler for this event
  void AddHandler(std::function<void()> handler) {
    mHandlers.emplace_back(handler);
  }
  // Loop over handlers and call each lambda
  void Trigger() {
    for (auto &f : mHandlers) {
      f();
    }
  }

 private:
  std::vector<std::function<void()>> mHandlers;
};

int main() {
  std::string name = "Sanjay";

  Event myEvent;
  myEvent.AddHandler([]() { std::cout << "This is handler 1" << std::endl; });
  myEvent.AddHandler(
      [&name]() { std::cout << "This is handler 2: " << name << std::endl; });
      
  name = "Ari";
  int x = 5;
  myEvent.AddHandler([&x]() { x++; });

  std::cout << "x = " << x << std::endl;
  myEvent.Trigger();
  std::cout << "x = " << x << std::endl;

  return 0;
}