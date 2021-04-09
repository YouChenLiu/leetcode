/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
  TreeNode *buildTree(const std::vector<int> &nums, int lower, int upper) {
    if (lower > upper) {
      return nullptr;
    }
    const auto median = (lower + upper) / 2;
    TreeNode *node = new TreeNode(nums[median]);
    node->left = buildTree(nums, lower, median - 1);
    node->right = buildTree(nums, median + 1, upper);
    return node;
  }
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return buildTree(nums, 0, nums.size() - 1);
  }
};
// @lc code=end
