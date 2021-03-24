/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
public:
  int addDigits(int num) {
    while (num / 10 != 0) {
      auto tmp = num;
      int sum = 0;
      while (tmp != 0) {
        sum += tmp % 10;
        tmp = tmp / 10;
      }
      num = sum;
    }
    return num;
  }
};
// @lc code=end
