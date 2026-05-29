
#include <iostream>
class Transaction {  // base class for all
 public:             // transactions
  Transaction() { logTransaction(); }
  virtual ~Transaction() { logTransaction(); }

  virtual void logTransaction() const {
    std::cout << "Transaction" << std::endl;
  }  // make type-dependent
  // log entry
};

class BuyTransaction : public Transaction {  // derived class
 public:
  virtual void logTransaction() const {
    std::cout << "BuyTransaction" << std::endl;
  }  // how to log trans-
     // actions of this type
};
class SellTransaction : public Transaction {  // derived class
 public:
  virtual void logTransaction() const {
    std::cout << "SellTransaction" << std::endl;
  }  // how to log trans-
     // actions of this type
};
int main(int argc, char const *argv[]) {
  // This will surprisingly call logTransaction from Transaction class not,
  // buyTransaction.
  BuyTransaction b;
  return 0;
}
