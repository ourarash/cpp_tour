#include <iostream>
#include <map>
#include <string>
int main(int argc, char const *argv[]) {
  std::map<int, std::string> mymap;

  if (auto [iter, success] = mymap.insert(std::make_pair(1, "hi"));
      success == true) {
    // insert succeeded, and result is valid for this block
    std::cout << "iter->firsts: " << iter->first << std::endl;
    // ...
  } else {
    std::cout << "iter->firsts: " << iter->first << std::endl;
  }
  // iter, success are destroyed here
  return 0;
}

// // Generating data
// std::vector<int> data = {1, 2, 3, 4, 5, ..., 1'000'000'000}; // 1 000 000 000
// items

// //Usage or iterating data
// for(auto e: data){

// }

// // Coroutine
// experimental::generator<int> coRoutine()
// {
//   for (int i { 0 }; i < 1000000000; ++i) {
//     co_yield i;
//   }
// }

// for(auto e: coRoutine() ){

// }