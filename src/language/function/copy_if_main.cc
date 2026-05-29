#include <iostream>
#include <numeric>
#include <vector>

struct Person {
  std::string first_name;
  std::string last_name;
  int age;
};
//-----------------------------------------------------
int main() {
  std::vector<int> from{1, 2, 3, 4, 5};
  std::vector<int> to;

  auto is_odd = [](const int& i) { return i % 2 == 1; };

  // Copy from the "from" container into the "to" container,
  // only if is_odd returns true for that element
  std::copy_if(from.begin(), from.end(), std::back_inserter(to), is_odd);

  std::vector<Person> students;
  std::vector<Person> students_older_than_18;

  int min_age = 18;

  std::copy_if(students.begin(), students.end(),
               std::back_inserter(students_older_than_18),
               [min_age](const Person& s) {
                 return s.age > min_age && s.last_name.size() > 10;
               });
}
