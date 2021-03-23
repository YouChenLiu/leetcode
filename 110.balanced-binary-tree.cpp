/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// Definition for a binary tree node.
#include <algorithm>
#include <climits>
#include <utility>
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

class Solution {
public:
  int getDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + std::max(getDepth(root->left), getDepth(root->right));
  }
  bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    if (std::abs(getDepth(root->left) - getDepth(root->right)) > 1) {
      return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
  }
};
// @lc code=end
