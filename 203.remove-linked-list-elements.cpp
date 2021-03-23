/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    // find head
    while (head != nullptr && head->val == val) {
      //   auto tmp = head;
      head = head->next;
      //   delete tmp;
    }
    auto root = head;
    while (head != nullptr && head->next != nullptr) {
      if (head->next->val == val) {
        // auto tmp = head->next;
        head->next = head->next->next;
        // delete tmp;
        continue;
      }
      head = head->next;
    }
    return root;
  }
};
// @lc code=end
