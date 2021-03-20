/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;
class Solution {
public:
  bool isPalindrome(string s) {
    if (s.length() == 1) {
      return true;
    }
    std::transform(s.begin(), s.end(), s.begin(),
                   [](char ch) { return std::tolower(ch); });
    s.erase(std::remove_if(
                s.begin(), s.end(),
                [](char c) { return !(std::isalpha(c) || std::isdigit(c)); }),
            s.end());
    if (s.length() == 0) {
      return true;
    }
    std::size_t lower = 0;
    std::size_t upper = s.length() - 1;
    while (lower < upper) {
      if (s[lower] != s[upper]) {
        return false;
      }
      lower++;
      upper--;
    }
    return true;
  }
};
// @lc code=end
