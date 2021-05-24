/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int countConsistentStrings(std::string allowed,
                             std::vector<std::string> &words) {
    std::unordered_set<char> set;
    for (const auto &ch : allowed) {
      set.insert(ch);
    }

    int count = words.size();
    for (const auto &word : words) {
      for (const auto &ch : word) {
        if (set.find(ch) == set.end()) {
          count--;
          break;
        }
      }
    }

    return count;
  }
};
// @lc code=end
