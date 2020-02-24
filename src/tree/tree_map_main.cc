#include "src/lib/utility.h"

#include <any>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

typedef std::map<std::string, std::any> Tree;

// A novel method for representing a binary tree in C++17 using atd::any
int main() {

  Tree t = Tree{{"val", 0},
                {"left", Tree{{"val", 1},
                              {"left", Tree{{"val", 3},
                                            {"left", Tree{{"val", 6}}},
                                            {"right", Tree{{"val", 1}}}}},
                              {"right", Tree{{"val", 4}}}}},
                {"right", Tree{{"val", 2}}}};

  return 0;
}