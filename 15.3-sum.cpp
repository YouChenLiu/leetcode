/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3) {
      return {};
    }

    std::sort(nums.begin(), nums.end());
    if (nums.front() > 0 || nums.back() < 0) {
      return {};
    }
    std::set<std::vector<int>> ans;
    for (std::size_t i = 0; i < nums.size() - 2; i++) {
      if (nums[i] > 0) {
        break;
      }
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      std::size_t lower = i + 1;
      std::size_t upper = nums.size() - 1;
      while (lower < upper) {
        const auto sum = nums[i] + nums[lower] + nums[upper];
        if (sum == 0) {
          ans.insert({nums[i], nums[lower], nums[upper]});
          lower++;
          upper--;
          continue;
        }
        if (sum < 0) {
          lower++;
        } else {
          upper--;
        }
      }
    }
    return std::vector<std::vector<int>>(ans.begin(), ans.end());
    // too slow
    /*
    if (nums.size() < 3) {
        return {};
    }
    std::set<std::vector<int>> ans;
    for (std::size_t i = 0; i < nums.size() - 2; i++) {
        const auto &numi = nums[i];
        for (std::size_t j = i + 1; j < nums.size() - 1; j++) {
        const auto &numj = nums[j];
        const auto &numij = numi + nums[j];
        for (std::size_t k = j + 1; k < nums.size(); k++) {
            const auto &numk = nums[k];
            const auto sum = numij + numk;
            if (sum == 0) {
            std::vector<int> tmp{numi, numj, numk};
            std::sort(tmp.begin(), tmp.end());
            ans.insert(tmp);
            }
        }
        }
    }

    return std::vector<std::vector<int>>(ans.begin(), ans.end());
    */
  }
};
// @lc code=end
