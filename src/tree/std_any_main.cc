#include "src/lib/utility.h"

#include <any>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main() {

  std::map<std::string, std::any> Notebook;

  std::string name{"Pluto"};
  int year = 2015;

  Notebook["PetName"] = name;
  Notebook["Born"] = year;

  std::string strS =
      std::any_cast<std::string>(Notebook["PetName"]); // = "Pluto"
  int intI = std::any_cast<int>(Notebook["Born"]);     // = 2015

  std::cout << "strS: " << strS << std::endl;
  std::cout << "intI: " << intI << std::endl;
  return 0;
}

typedef std::map<std::string, std::any> Tree;


int main2() {

  Tree t1 = Tree{{"val", 0},
           {"left", Tree{{"val", 1},
                         {"left", Tree{{"val", 3},
                                       {"left", Tree{{"val", 6}}},
                                       {"right", Tree{{"val", 1}}}}},
                         {"right", Tree{{"val", 4}}}}},
           {"right", Tree{{"val", 2}}}};


  {
    'val': 'A',
    'left': {
        'val': 'B',
        'left': {'val': 'D'},
        'right': {'val': 'E'}
    },
    'right': {
        'val': 'C',
        'right': {'val': 'F'}
    }
 }
  
  return 0;
}