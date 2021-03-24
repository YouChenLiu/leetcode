/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
  int missingNumber(vector<int> &nums) {
    std::size_t n = nums.size();
    if (n == 1) {
      return 1 - nums[0];
    }
    auto sum = n * (n + 1) / 2;
    for (const auto &num : nums) {
      sum -= num;
    }
    return (sum == 0) ? 0 : sum;
  }
};
// @lc code=end
