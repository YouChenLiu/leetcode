/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }

    ListNode *merged = new ListNode();
    auto head = merged;
    while (head != nullptr) {
      if (l1 == nullptr) {
        head->val = l2->val;
        l2 = l2->next;
        if (l2 != nullptr) {
          head->next = new ListNode();
        }
        head = head->next;
        continue;
      }
      if (l2 == nullptr) {
        head->val = l1->val;
        l1 = l1->next;
        if (l1 != nullptr) {
          head->next = new ListNode();
        }
        head = head->next;
        continue;
      }
      if (l1->val < l2->val) {
        head->val = l1->val;
        l1 = l1->next;
      } else {
        head->val = l2->val;
        l2 = l2->next;
      }
      if (l1 != nullptr || l2 != nullptr) {
        head->next = new ListNode();
      }
      head = head->next;
    }

    return merged;
  }
};
// @lc code=end
