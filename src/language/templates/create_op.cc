#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include<map>
struct Op {
  virtual const char* GetName() const = 0;
  virtual void Parse(const std::string& params) = 0;
  virtual void Execute(class Machine& machine) = 0;
};

template <typename T>
std::shared_ptr<Op> CreateOp() {
  return std::make_shared<T>();
}

std::map<std::string, std::function<std::shared_ptr<Op>()>> opMap;
