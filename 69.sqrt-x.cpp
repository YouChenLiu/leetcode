/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
#include <cmath>
class Solution {
public:
  int mySqrt(int x) { return static_cast<int>(std::floor(std::sqrt(x))); }
};
// @lc code=end
