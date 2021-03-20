/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 1) {
      return strs[0];
    }
    std::size_t minLen = 200;
    for (const auto &str : strs) {
      if (str.length() < minLen)
        minLen = str.length();
    }
    if (minLen == 0)
      return "";
    if (minLen == 200)
      return "";

    int count = 0;
    for (std::size_t i = 1; i <= minLen; i++) {
      const auto prefix = strs[0].substr(0, i);

      for (const auto &str : strs) {
        if (str.find(prefix) != 0) {
          break;
        }
        count++;
      }

      if (count != strs.size()) {
        if (i == 1) {
          return "";
        }
        return prefix.substr(0, prefix.length() - 1);
      }
      count = 0;
      if (minLen == 1) {
        return prefix;
      }
    }

    return strs[0].substr(0, minLen);
  }
};
// @lc code=end
