#include <iostream>
#include <string>

class Investment {
 public:
  virtual ~Investment() {}  // This is essential
};
class Stock : public Investment {};
class Bond : public Investment {};
class RealEstate : public Investment {};

auto delInvmt = [](Investment* pInvestment)  // custom
{                                            // deleter
  // makeLogEntry(pInvestment);                 // (a lambda
  delete pInvestment;  // expression)
};

//-----------------------------------------------------------------------------
template <typename... Ts>                        // revised
std::unique_ptr<Investment, decltype(delInvmt)>  // return type

makeInvestment(int i, Ts&&... params) {
  std::unique_ptr<Investment, decltype(delInvmt)>  // ptr to be
      pInv(nullptr, delInvmt);
  if (i == 1) {
    pInv.reset(new Stock(std::forward<Ts>(params)...));
  } else if (i == 2) {
    pInv.reset(new Bond(std::forward<Ts>(params)...));
  } else if (i == 3) {
    pInv.reset(new RealEstate(std::forward<Ts>(params)...));
  }
  return pInv;
}
//-----------------------------------------------------------------------------
template <typename... Ts>
auto makeInvestment14(int i, Ts&&... params)  // C++14
{
  std::unique_ptr<Investment, decltype(delInvmt)>  // ptr to be
      pInv(nullptr, delInvmt);
  if (i == 1) {
    pInv.reset(new Stock(std::forward<Ts>(params)...));
  } else if (i == 2) {
    pInv.reset(new Bond(std::forward<Ts>(params)...));
  } else if (i == 3) {
    pInv.reset(new RealEstate(std::forward<Ts>(params)...));
  }
  return pInv;
}
