#include <any>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "src/lib/utility.h"

int main() {
  std::map<std::string, std::any> Notebook;

  std::string name{"Pluto"};
  int year = 2015;

  Notebook["PetName"] = name;
  Notebook["Born"] = year;

  std::string strS =
      std::any_cast<std::string>(Notebook["PetName"]);  // = "Pluto"
  int intI = std::any_cast<int>(Notebook["Born"]);      // = 2015

  std::cout << "strS: " << strS << std::endl;
  std::cout << "intI: " << intI << std::endl;
  return 0;
}
