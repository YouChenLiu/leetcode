/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
  bool isPowerOfFour(int n) {
    if (n <= 0) {
      return false;
    }
    if (n == 1) {
      return true;
    }
    const auto mask = 0x55555554;
    const auto isOnlyOneBit = (n & (n - 1)) == 0;
    return (n | mask) == mask && isOnlyOneBit;
  }
};
// @lc code=end
