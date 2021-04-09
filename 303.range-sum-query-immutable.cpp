/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
#include <numeric>
#include <vector>

using namespace std;

class NumArray {
public:
  std::vector<int> acc;
  NumArray(vector<int> &nums) {
    acc.resize(nums.size());
    std::partial_sum(nums.begin(), nums.end(), acc.begin());
    for (const auto &val : acc) {
      std::cout << val << " ";
    }
  }

  int sumRange(int left, int right) {
    const auto leftVal = left == 0 ? 0 : acc[left - 1];
    if (left == right) {
      return acc[left] - leftVal;
    }
    return acc[right] - leftVal;
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
