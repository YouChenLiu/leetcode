/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    if (head->next == nullptr) {
      return head;
    }
    const auto ori = head;
    while (head != nullptr) {
      if (head->next == nullptr) {
        break;
      }
      if (head->val == head->next->val) {
        const auto next = head->next->next;
        delete head->next;
        head->next = next;
        continue;
      }
      head = head->next;
    }
    return ori;
  }
};
// @lc code=end
