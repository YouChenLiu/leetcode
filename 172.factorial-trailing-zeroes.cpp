/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
#include <algorithm>
class Solution {
public:
  int trailingZeroes(int n) {
    int ans = 0;
    // count n / 5^1 + n / 5^2 + n / 5^3 + n / 5^4 ...
    for (int i = 5; n / i != 0; i *= 5) {
      ans += n / i;
    }
    return ans;
  }
};
// @lc code=end
