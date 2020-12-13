#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = dict()
        for idx in range(0, len(nums)):
            key = target - nums[idx]
            if key in table:
                return [table[key], idx]
            else:
                table[nums[idx]] = idx
# @lc code=end
