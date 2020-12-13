import operator
#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#


# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 1:
            return 1
        maxWinSize = 0
        for startIdx in range(0, len(s)):
            winSize = maxWinSize
            while startIdx + winSize <= len(s):
                subStr = s[startIdx:startIdx + winSize]
                if len(set(subStr)) >= winSize:
                    maxWinSize = winSize
                    winSize += 1
                else:
                    break
        return maxWinSize

# @lc code=end


if __name__ == "__main__":
    sol = Solution()
    if sol.lengthOfLongestSubstring('abcabcbb') is not 3:
        print('error', 1)
    if sol.lengthOfLongestSubstring('bbbbb') is not 1:
        print('error', 2)
    if sol.lengthOfLongestSubstring('pwwkew') is not 3:
        print('error', 3)
    if sol.lengthOfLongestSubstring(' ') is not 1:
        print('error', 4)
    print(sol.lengthOfLongestSubstring('au'))
