#include <any>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

typedef std::map<std::string, std::any> Tree;

void PrintTreeInorder(Tree &t) {
  if (t.count("left") == 1) {
    PrintTreeInorder(std::any_cast<Tree &>(t["left"]));
  }
  if (t.count("val_int") == 1) {
    std::cout << "val: " << std::any_cast<int>(t["val"]) << std::endl;
  }
  if (t.count("val_char") == 1) {
    std::cout << "val: " << std::any_cast<char>(t["val_char"]) << std::endl;
  }
  if (t.count("right") == 1) {
    PrintTreeInorder(std::any_cast<Tree &>(t["right"]));
  }
}
// A novel method for representing a binary tree in C++17 using std::any
int main() {
  //   {
  //   "val": 0,
  //   "left": {
  //     "val": 1,
  //     "left": {
  //       "left": {
  //         "val": 3,
  //         "left": {
  //           "val": 6
  //         },
  //         "right": {
  //           "val": 1
  //         }
  //       }
  //     },
  //     "right": {
  //       "val": 4
  //     }
  //   },
  //   "right": {
  //     "val": 2
  //   }
  // }

  Tree t = Tree{{"val", 0},
                {"left", Tree{{"val", 1},
                              {"left", Tree{{"val", 3},
                                            {"left", Tree{{"val", 6}}},
                                            {"right", Tree{{"val", 1}}}}},
                              {"right", Tree{{"val", 4}}}}},
                {"right", Tree{{"val", 2}}}};
  PrintTreeInorder(t);
  return 0;
}