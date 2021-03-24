/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    std::vector<std::string> ans;
    using Node = std::pair<TreeNode *, int>;
    std::stack<Node> stack;
    std::vector<int> path;
    // s.push_back(root->val + '0');
    stack.push({root, 1});
    while (!stack.empty()) {
      const auto node = stack.top();
      const auto &tree = node.first;
      const auto &layer = node.second;
      stack.pop();
      path.resize(layer - 1);
      if (tree->left == nullptr && tree->right == nullptr) {
        std::string s;
        for (int i = 0; i < path.size(); i++) {
          s = s + std::to_string(path[i]) + "->";
        }
        s += std::to_string(tree->val);
        ans.push_back(s);
      }
      if (tree->right != nullptr) {
        stack.push({tree->right, layer + 1});
      }
      if (tree->left != nullptr) {
        stack.push({tree->left, layer + 1});
      }
      path.push_back(tree->val);
    }
    return ans;
  }
};
// @lc code=end
