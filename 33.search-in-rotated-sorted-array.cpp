/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int lower = 0;
    int upper = nums.size() - 1;
    while (lower <= upper) {
      const auto median = (lower + upper) / 2;
      //   std::cout << lower << ", " << median << ", " << upper << std::endl;
      const auto &l = nums[lower];
      const auto &m = nums[median];
      const auto &u = nums[upper];
      if (m == target) {
        return median;
      }
      if (l <= m) {
        if (l <= target && target < m) {
          upper = median - 1;
        } else {
          lower = median + 1;
        }
      } else {
        if (m < target && target <= u) {
          lower = median + 1;
        } else {
          upper = median - 1;
        }
      }
    }
    return -1;
  }
};
// @lc code=end
