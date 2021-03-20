/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int titleToNumber(string columnTitle) {
    unsigned int ans = 0;
    unsigned int base = 1;
    while (!columnTitle.empty()) {
      const auto current = columnTitle.back() - 'A' + 1;
      columnTitle.pop_back();
      ans += base * current;
      base *= 26;
    }
    return ans;
  }
};
// @lc code=end
