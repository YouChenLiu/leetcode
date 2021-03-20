/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
  string convertToTitle(int columnNumber) {
    std::string result;
    while (columnNumber != 0) {
      const auto res = (columnNumber - 1) % 26;
      const auto alpha = 'A' + res;
      result.insert(result.begin(), alpha);
      columnNumber = (columnNumber - 1) / 26;
    }
    return result;
  }
};
// @lc code=end
