/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    return nums.size();
  }
};
// @lc code=end
