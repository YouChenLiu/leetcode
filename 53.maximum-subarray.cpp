/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start

#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
  std::vector<int> arr;
  std::vector<int> accumulated;
public:
  int calSum(std::size_t l, std::size_t r) {
    if (l == r) {
      return arr[l];
    }
    if (l == 0) {
      return accumulated[r];
    }
    return accumulated[r] - accumulated[l - 1];
  }
  int maxSubArray(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    arr = nums;
    accumulated.push_back(nums[0]);
    for (std::size_t i = 1; i < nums.size(); i++) {
      accumulated.push_back(accumulated[i - 1] + nums[i]);
    }
    int max = accumulated[0];
    std::size_t lower = 0;
    while (lower < nums.size()) {
      std::size_t upper = lower;
      while (upper < nums.size()) {
        const auto current = calSum(lower, upper);
        if (current > max) {
          max = current;
        }
        upper++;
      }
      lower++;
    }
    return max;
  }
};
// @lc code=end
