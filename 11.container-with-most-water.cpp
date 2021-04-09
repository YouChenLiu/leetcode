/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int lower = 0;
    int upper = height.size() - 1;
    int maxCapacity = 0;
    while (lower < upper) {
      const auto &l = height[lower];
      const auto &r = height[upper];
      const auto capacity = (upper - lower) * std::min(l, r);
      if (maxCapacity < capacity) {
        maxCapacity = capacity;
      }
      if (l < r) {
        lower++;
      } else {
        upper--;
      }
    }

    return maxCapacity;
  }
};
// @lc code=end
