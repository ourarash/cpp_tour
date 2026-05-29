class Solution {
 public:
  std::vector<std::string> WordBreak(std::string &s,
                                     std::vector<std::string> &dic) {
    std::vector<std::string> result;
    std::vector<std::string> curResult;
    // std::unordered_map<std::string, std::vector<std::string>> memo;
    std::unordered_map<std::string, std::vector<std::vector<std::string>>> memo;
    WordBreak_aux_memo(s, dic, curResult, result, memo);
    return result;
  }
  std::string Join(const std::vector<std::string> &strings) {
    std::string joined_string;
    for (int i = 0; i < strings.size(); i++) {
      joined_string += strings[i];
      if (i < strings.size() - 1) {
        joined_string += " ";
      }
    }

    return joined_string;
  }

  std::vector<std::vector<std::string>> Backtracking::WordBreak_aux_memo(
      std::string &s, std::vector<std::string> &dic,
      std::vector<std::string> &curResult, std::vector<std::string> &result,
      std::unordered_map<std::string, std::vector<std::vector<std::string>>>
          &memo) {
    if (memo.count(s) > 0) {
      std::vector<std::vector<std::string>> returnValue;
      for (auto &e : memo[s]) {
        std::vector<std::string> combined = curResult;
        combined.insert(combined.end(), e.begin(), e.end());
        returnValue.push_back(combined);
        result.push_back(Backtracking::Join(combined));
      }

      return returnValue;
    }

    if (s.size() == 0) {
      result.push_back(Backtracking::Join(curResult));
      return {{}};
    }

    for (auto word : dic) {
      // If s starts with word
      if (s.rfind(word, 0) == 0) {
        // Update s and curResult
        auto new_s = s.substr(word.size());
        curResult.push_back(word);

        auto partial = Backtracking::WordBreak_aux_memo(new_s, dic, curResult,
                                                        result, memo);
        for (auto &e : partial) {
          std::vector<std::string> t = {curResult};
          t.insert(t.end(), e.begin(), e.end());
          memo[s].push_back(t);
        }

        // Reset curResult
        curResult.pop_back();
      }
    }
    return memo[s];
  }
};