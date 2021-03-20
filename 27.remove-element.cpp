/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    nums.erase(std::remove_if(nums.begin(), nums.end(),
                              [val](auto v) { return v == val; }),
               nums.end());
    return nums.size();
  }
};
// @lc code=end
