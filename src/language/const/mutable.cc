#include <iostream>
#include <string>
class CTextBlock {
 public:
  std::size_t length() const;

 private:
  char *pText;
  mutable std::size_t textLength;  // these data members may
  mutable bool lengthIsValid;      // always be modified, even in
};                                 // const member functions
std::size_t CTextBlock::length() const {
  if (!lengthIsValid) {
    textLength = std::strlen(pText);  // now fine
    lengthIsValid = true;             // also fine
  }
  return textLength;
}