/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    if (nums.size() == 1) {
      return {std::to_string(nums[0])};
    }
    std::vector<std::string> ans;
    int left = 0;
    int right = 1;
    while (right < nums.size()) {
      if (nums[right - 1] + 1 != nums[right]) {
        if (right - left == 1) {
          ans.push_back(std::to_string(nums[left]));
        } else {
          const auto l = std::to_string(nums[left]);
          const auto r = std::to_string(nums[right - 1]);
          ans.push_back(l + "->" + r);
        }
        left = right;
        right = left;
      }
      if (left == nums.size() - 1) {
        ans.push_back(std::to_string(nums[left]));
        break;
      }
      if (right == nums.size() - 1) {
        const auto l = std::to_string(nums[left]);
        const auto r = std::to_string(nums[right]);
        ans.push_back(l + "->" + r);
        break;
      }
      right++;
    }
    return ans;
  }
};
// @lc code=end
