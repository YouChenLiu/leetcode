/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
  bool isIsomorphic(std::string s, std::string t) {
    std::unordered_map<char, char> map;
    std::unordered_set<char> set;
    for (std::size_t i = 0; i < s.size(); i++) {
      const auto &src = s[i];
      const auto &dst = t[i];
      const auto it = map.find(src);
      if (it == map.end()) {
        if (set.find(dst) != set.end()) {
          return false;
        }
        map.insert({src, dst});
        set.insert(dst);
        continue;
      }

      if (it->second != dst) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
