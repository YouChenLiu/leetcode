/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
  bool isHappy(int n) {
    const auto maxIter = 10;
    int count = 0;
    while (n != 0 && count++ < maxIter) {
      auto m = n;
      int sum = 0;
      while (m != 0) {
        const auto digit = m % 10;
        sum += digit * digit;
        m /= 10;
      }
      if (sum == 1) {
        return true;
      }
      n = sum;
    }
    return false;
  }
};
// @lc code=end
