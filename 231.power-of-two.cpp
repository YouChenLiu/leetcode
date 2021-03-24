/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n < 0) {
      return false;
    }
    int count = 0;
    while (n != 0) {
      count += n & 0x01;
      n >>= 1;
    }
    return count == 1;
  }
};
// @lc code=end
