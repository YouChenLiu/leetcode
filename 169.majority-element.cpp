/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    // https://en.wikipedia.org/wiki/Boyer–Moore_majority_vote_algorithm
    int m = nums[0];
    int count = 1;
    for (std::size_t i = 1; i < nums.size(); i++) {
      const auto val = nums[i];
      if (count == 0) {
        m = val;
        count++;
      } else {
        count += (m == val ? 1 : -1);
      }
    }
    return m;
  }
};
// @lc code=end
