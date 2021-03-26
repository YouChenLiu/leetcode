/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// @lc code=start

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    const auto pVal = p->val;
    const auto qVal = q->val;
    auto node = root;
    while (node != nullptr) {
      const auto &val = node->val;
      if (pVal < val && qVal < val) {
        node = node->left;
      } else if (pVal > val && qVal > val) {
        node = node->right;
      } else {
        return node;
      }
    }
    return nullptr;
  }
};
// @lc code=end
