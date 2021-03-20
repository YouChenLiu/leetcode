/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start

#include <unordered_set>

class Solution {
public:
  bool hasCycle(ListNode *head) {
    // save nodes to set then check who visit again
    // too slow
    /*
    std::unordered_set<ListNode *> set;
    while (head != nullptr) {
      const auto it = set.find(head);
      if (it != set.end()) {
        return true;
      }
      set.insert(head);
      head = head->next;
    }
    return false;
    */
    // let fast to trace slow
    // there is a loop if fast == slow
    if (head == nullptr) {
      return false;
    }
    auto slow = head;
    auto fast = head->next;
    while (fast != nullptr && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
