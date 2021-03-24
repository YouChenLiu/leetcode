/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// The API isBadVersion is defined for you.
bool isBadVersion(int version);
// @lc code=start

class Solution {
public:
  int firstBadVersion(int n) {
    if (n == 1) {
      return 1;
    }
    unsigned int lower = 1;
    unsigned int upper = n;
    unsigned int midian = 0;
    while (true) {
      midian = (lower + upper) / 2;
      const auto pre = isBadVersion(midian - 1);
      const auto current = isBadVersion(midian);
      if ((pre == false) && (current == true)) {
        break;
      }
      if (current == false && isBadVersion(midian + 1) == true) {
        midian = midian + 1;
        break;
      }
      if (pre == true) {
        upper = midian;
      } else {
        lower = midian;
      }
    }
    return midian;
  }
};
// @lc code=end
