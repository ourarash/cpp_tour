#include <cmath>
#include <iostream>
#include <string>
#include <vector>
class ConsonantAndVowels {
 public:
  int GetMaxDiffOfConsonantAndVowels(std::string &s, int l, int r) {
    const std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int number_of_consonants = 0, number_of_vowels = 0;
    for (int i = l; i <= r; i++) {
      auto c = s[i];
      if (std::find(vowels.begin(), vowels.end(), c) != vowels.end()) {
        number_of_vowels++;
      } else {
        number_of_consonants++;
      }
    }
    return std::abs(number_of_consonants - number_of_vowels);
  }

  int CVImbalance(std::string &s, int l, int r) {
    int N = r - l + 1;
    if (N == 0 || N == 1) {
      return N;
    }
    int m;  
    if (N % 2 == 0) {
      m = (r + l) / 2;
    } else {
      m = (r + l - 1) / 2;
    }
    int max_diff_of_consonant_and_vowels =
        GetMaxDiffOfConsonantAndVowels(s, l, r);
    int cv_imbalance_left = CVImbalance(s, l, m);
    int cv_imbalance_right = CVImbalance(s, m + 1, r);
    return max_diff_of_consonant_and_vowels + cv_imbalance_left +
           cv_imbalance_right;
  }
};