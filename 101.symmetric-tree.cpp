/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
#include <stack>
class Solution {
public:
  using Node = std::pair<TreeNode *, TreeNode *>;
  bool isSymmetric(TreeNode *root) {
    std::stack<Node> stack;
    stack.push({root->left, root->right});
    while (!stack.empty()) {
      const auto node = stack.top();
      stack.pop();
      if ((node.first == nullptr && node.second != nullptr) ||
          (node.first != nullptr && node.second == nullptr)) {
        return false;
      }
      if (node.first == nullptr && node.second == nullptr) {
        continue;
      }
      if (node.first->val != node.second->val) {
        return false;
      }
      stack.push({node.first->left, node.second->right});
      stack.push({node.first->right, node.second->left});
    }
    return true;
  }
};
// @lc code=end
