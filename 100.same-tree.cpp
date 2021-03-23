/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
  using Node = std::pair<TreeNode *, TreeNode *>;
  bool isSameTree(TreeNode *p, TreeNode *q) {
    std::stack<Node> stack;
    stack.push({p, q});
    while (!stack.empty()) {
      const auto node = stack.top();
      stack.pop();
      const auto &p = node.first;
      const auto &q = node.second;
      if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) {
        return false;
      }
      if (p == nullptr) {
        continue;
      }
      if (p->val != q->val) {
        return false;
      }
      stack.push({p->right, q->right});
      stack.push({p->left, q->left});
    }
    return true;
  }
};
// @lc code=end
