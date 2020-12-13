#
# @lc app=leetcode id=5 lang=python3
#
# [5] Longest Palindromic Substring
#

# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 0:
            return s
        if len(s) <= 2:
            return s[0:0]


# @lc code=end
