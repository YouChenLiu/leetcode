/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  bool wordPattern(string pattern, string s) {
    std::stringstream ss(s);
    std::vector<std::string> vec(26, "");
    std::set<std::string> set;
    std::string word;
    for (int i = 0; i < pattern.size(); i++) {
      ss >> word;
      const auto &c = pattern[i];
      auto &w = vec[c - 'a'];
      if (w.empty()) {
        w = word;
        set.insert(w);
        continue;
      } else {
        if (w != word) {
          return false;
        }
      }
    }
    if (!ss.eof()) {
      return false;
    }
    std::set<char> count(pattern.begin(), pattern.end());
    return set.size() == count.size();
  }
};
// @lc code=end
