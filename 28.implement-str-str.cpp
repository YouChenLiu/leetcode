/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) { return haystack.find(needle); }
};
// @lc code=end
