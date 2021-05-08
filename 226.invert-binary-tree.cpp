/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
#include <queue>
class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }
    auto head = root;
    std::queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
      const auto top = queue.front();
      queue.pop();
      auto tmp = top->left;
      top->left = top->right;
      top->right = tmp;

      if (top->left != nullptr) {
        queue.push(top->left);
      }
      if (top->right != nullptr) {
        queue.push(top->right);
      }
    }
    return root;
  }
};
// @lc code=end
