#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "adjacency_vector_of_set.h"
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

/* Sketchpad notes left by the original author:
   1 -------> 2
   { 1, {2}};
   { 2, {}};
   std::pair<>
*/
