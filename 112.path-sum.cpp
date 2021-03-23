/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
#include <utility>

class Solution {
public:
  using Node = std::pair<TreeNode *, int>;
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return false;
    }

    std::stack<Node> stack;
    stack.push({root, 0});
    while (!stack.empty()) {
      const auto node = stack.top();
      stack.pop();
      const auto &tree = node.first;
      const auto &sum = node.second;
      if (tree == nullptr) {
        continue;
      }
      if (((tree->val + sum) == targetSum) &&
          (tree->left == nullptr && tree->right == nullptr)) {
        return true;
      }
      stack.push({tree->right, sum + tree->val});
      stack.push({tree->left, sum + tree->val});
    }
    return false;
  }
};
// @lc code=end
