/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  using Node = std::pair<TreeNode *, int>;
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    std::queue<Node> unvisited;
    std::queue<Node> visited;
    unvisited.push({root, 0});
    while (!unvisited.empty()) {
      const auto node = unvisited.front();
      unvisited.pop();
      const auto &tree = node.first;
      const auto &layer = node.second;
      if (tree->left != nullptr) {
        unvisited.push({tree->left, layer + 1});
      }
      if (tree->right != nullptr) {
        unvisited.push({tree->right, layer + 1});
      }
      visited.push(node);
    }

    std::vector<std::vector<int>> tmp(visited.back().second + 1,
                                      std::vector<int>());
    while (!visited.empty()) {
      const auto node = visited.front();
      visited.pop();
      const auto &tree = node.first;
      const auto &layer = node.second;
      tmp[layer].push_back(tree->val);
    }
    std::vector<std::vector<int>> ans(tmp.rbegin(), tmp.rend());
    return ans;
  }
};
// @lc code=end
