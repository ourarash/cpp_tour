#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <vector>

// void hazf() {
//   char c[] = "This is a test.";
//   count_matches(c, 't');

//   std::string s = "This is a test.";
//   count_matches(s, 't');
// }

int main() {
  {
    char c[] = "This is a test.";
    std::string s = c;
    std::string_view sv1 = c;
    // Copy the view.
    std::string_view sv2 = sv1;

    // Modify original.
    c[0] = '$';

    std::cout << "c: " << c << std::endl;
    std::cout << "s: " << s << std::endl;
    std::cout << "sv1: " << sv1 << std::endl;

    std::cout << "sv2: " << sv2 << std::endl;
  }

  {
    std::string_view sv1{"this is a test"};

    std::string_view sv2{sv1};
    std::string_view sv3{sv2};

    std::cout << "sv1: " << sv1 << ", sv2: " << sv2 << ", sv3: " << sv3
              << std::endl;
  }

  {
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Modifying the view" << std::endl;
    char c[] = "This is a test.";
    std::string_view sv = c;

    // Remove the first 2 characters from the view.
    sv.remove_prefix(2);
    std::cout << "sv: " << sv << std::endl;

    // Remove the last 2 characters from the view.
    sv.remove_suffix(2);
    std::cout << "sv: " << sv << std::endl;
    std::cout << "c: " << c << std::endl;
  }

  {
    std::cout << "------------------------------------------" << std::endl;

    char c1[] = "This is a test.";
    std::string_view sv1{c1};

    char c2[]{'t', 'e', 's', 't', 's'};
    std::string_view sv2{c2, 5};

    std::cout << "sv1: " << sv1 << std::endl;
    std::cout << "sv2: " << sv2 << std::endl;
  }

  {
    std::cout << "------------------------------------------" << std::endl;
    std::string_view sv;

    char *c2, *c3;
    c2 = new char[2];
    c2[0] = 'a';
    c2[1] = '\0';
    sv = c2;
    std::cout << "sv: " << sv << std::endl;
    delete c2;

    c3 = new char[2];
    c3[0] = '?';
    c3[1] = '\0';
    std::cout << "c3: " << c3 << std::endl;

    std::cout << "sv: " << sv << std::endl;
  }

  {
    std::cout << "------------------------------------------" << std::endl;
    char c[] = "This is a test.";
    std::string s{c};
    std::cout << "std::strlen(s): " << std::strlen(s.c_str()) << std::endl;

    std::string_view sv{c};
    std::cout << "std::strlen(sv.data()): " << std::strlen(sv.data())
              << std::endl;
  }

  {
    char c[] = "This is a test.";

    std::string_view sv{c};
    std::cout << "sv: " << sv << std::endl;
    sv.remove_prefix(2);
    std::cout << "sv: " << sv << std::endl;
    std::cout << "sv.data(): " << sv.data() << std::endl;
  }

  {
    std::cout << "------------------------------------------" << std::endl;
    std::string_view sv{"This is a test."};
    sv.remove_prefix(5);
    sv.remove_suffix(5);

    std::cout << "sv: " << sv << std::endl;

    std::cout << "sv.data(): " << sv.data() << std::endl;
  }
  {
    std::cout << "------------------------------------------" << std::endl;
    char c[] = "This is a test.";

    std::string_view sv{c};
    c[std::strlen(c)] = 'a';
    std::cout << "sv: " << sv << std::endl;
    std::cout << "sv.data(): " << sv.data() << std::endl;
  }

  {
    std::cout << "------------------------------------------" << std::endl;

    auto s1{std::string_view{"aaaa"}};
    auto s2{std::string_view{"bbbb"}};

    std::cout << "s1, s2 Before : " << s1 << ", " << s2 << "\n";
    s1.swap(s2);
    std::cout << "s1, s2 After  : " << s1 << ", " << s2 << "\n";
  }
  return 0;
}
