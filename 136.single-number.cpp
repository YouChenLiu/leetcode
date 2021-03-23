/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    int ans = 0;
    for (const auto &num : nums) {
      ans ^= num;
    }
    return ans;
  }
};
// @lc code=end
