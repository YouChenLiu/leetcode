/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    const auto size = nums.size();
    nums.erase(std::remove(nums.begin(), nums.end(), 0), nums.end());
    nums.resize(size, 0);
  }
};
// @lc code=end
