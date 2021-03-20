/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start

#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    std::vector<int> ans(2);
    std::map<int, int> map{{target - numbers[0], 0}};
    for (std::size_t i = 1; i < numbers.size(); i++) {
      const auto &current = numbers[i];
      const auto diff = target - current;
      const auto it = map.find(current);
      if (it != map.end()) {
        ans[0] = it->second + 1;
        ans[1] = i + 1;
        break;
      }
      map.insert({diff, i});
    }
    return ans;
  }
};
// @lc code=end
