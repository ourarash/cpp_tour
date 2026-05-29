#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main() {
  /*
   * decltype() function introduced in C++ 11.
   *
   * This function detect the type of any variable
   *  and provide same data type to the new variable.
   *
   *  Ex:
   *  	string str; // type of str is string
   *  	decltype(str) name; // Creating a new variable name of string type
   */

  // typeid() Example
  cout << "typeid(int) = " << typeid(5).name() << endl;
  cout << "typeid(double) = " << typeid((double)5.2).name() << endl;
  cout << "typeid(float) = " << typeid((float)5.3).name() << endl;
  cout << "typeid(string) = " << typeid("India").name() << endl;

  cout << "-----" << endl;  // Line Divider

  // decltype example
  string value = "abc";
  decltype(value) name = "xyz";

  cout << "typeid(value) = " << typeid(value).name() << endl;
  cout << "typeid(name) = " << typeid(name).name() << endl;

  cout << "value = " << value << endl;
  cout << "name = " << name << endl;

  return 0;
}