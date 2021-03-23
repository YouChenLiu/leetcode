/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <algorithm>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    // poor space
    /*
    std::set<int> set(nums.begin(), nums.end());
    return nums.size() != set.size();
    */

    // hash table -> not best
    /*
    std::unordered_set<int> set;
    for (const auto &i : nums) {
      if (set.find(i) != set.end()) {
        return true;
      }
      set.insert(i);
    }
    return false;
    */

    // sort first and find repeated element
    std::sort(nums.begin(), nums.end());
    for (std::size_t i = 1; i < nums.size(); i++) {
      if (nums[i - 1] == nums[i]) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
