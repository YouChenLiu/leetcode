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
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    int lower = 0;
    int upper = nums.size() - 1;
    int median = (lower + upper) / 2;
    while ()
  }
};
// @lc code=end
