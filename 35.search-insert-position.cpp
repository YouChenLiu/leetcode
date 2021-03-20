/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    auto lhs = nums[0];
    if (target <= lhs) {
      return 0;
    }
    if (target > nums[nums.size() - 1]) {
      return nums.size();
    }
    for (std::size_t i = 1; i < nums.size(); i++) {
      const auto rhs = nums[i];
      if ((rhs == target) || (lhs < target && target < rhs)) {
        return i;
      }
    }
    return nums.size();
  }
};
// @lc code=end
