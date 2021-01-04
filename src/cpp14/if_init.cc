#include <string>
#include <map>



map<int, string> mymap;

int main(int argc, char const *argv[]) {
  
  if (auto result = mymap.insert(value); result.second == true) {
    // insert succeeded, and result is valid for this block
    use(result.first);  // ok
                        // ...
  }                     // result is destroyed here
  else {

  }
  return 0;
}


// Generating data
std::vector<int> data = {1, 2, 3, 4, 5, ..., 1'000'000'000}; // 1 000 000 000 items

//Usage or iterating data
for(auto e: data){

}



// Coroutine
experimental::generator<int> coRoutine()
{
  for (int i { 0 }; i < 1000000000; ++i) {
    co_yield i;
  }
}

for(auto e: coRoutine() ){

}