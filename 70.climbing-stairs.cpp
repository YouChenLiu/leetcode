/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
#include <map>
#include <type_traits>
class Solution {
public:
  std::map<int, int> map;
  int recursive(int n) {
    const auto it = map.find(n);
    if (it != map.end()) {
      return it->second;
    } else {
      const auto a = map.insert({n - 1, recursive(n - 1)}).first->second;
      const auto b = map.insert({n - 2, recursive(n - 2)}).first->second;
      return a + b;
    }
  }
  int climbStairs(int n) {
    map.insert({1, 1});
    map.insert({2, 2});
    return recursive(n);
  }
};
// @lc code=end
