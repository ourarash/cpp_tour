#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "src/lib/graph/adjacency_vector_of_set.h"
#include "src/lib/utility.h"

int main() {
  Graph g(
    { // Vector
      Vertex(0, {1, 2, 3}),  // Vertex object
    Vertex(1, {0, 2, 3}), 
    Vertex(2, {0, 1, 3}),           
    Vertex(3, {0, 1, 2})}
           );
  std::cout << g.IsEulerWalkable() << std::endl;
}


   1 -------> 2

   { 1, {2}};
   { 2, {}};
std::pair<>
