/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
#include <stack>

class Solution {
public:
  std::stack<ListNode *> stack;
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    stack.push(nullptr);
    stack.push(head);
    while (stack.top() != nullptr) {
      stack.push(stack.top()->next);
    }
    stack.pop();
    const auto ans = stack.top();
    auto root = stack.top();
    stack.pop();
    while (!stack.empty()) {
      root->next = stack.top();
      root = root->next;
      stack.pop();
    }

    return ans;
  }
};
// @lc code=end
