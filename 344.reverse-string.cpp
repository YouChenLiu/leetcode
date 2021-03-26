/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    for (std::size_t i = 0; i < s.size() / 2; i++) {
      auto &l = s[i];
      auto &r = s[s.size() - 1 - i];
      const auto tmp = l;
      l = r;
      r = tmp;
    }
  }
};
// @lc code=end
