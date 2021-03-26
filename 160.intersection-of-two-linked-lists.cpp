/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto calLength = [](ListNode *node) {
      int length = 0;
      while (node != nullptr) {
        node = node->next;
        length++;
      }
      return length;
    };

    const auto lengthA = calLength(headA);
    const auto lengthB = calLength(headB);

    auto ha = headA;
    auto hb = headB;
    if (lengthA > lengthB) {
      for (int i = 0; i < lengthA - lengthB; i++) {
        ha = ha->next;
      }
    } else {
      for (int i = 0; i < lengthB - lengthA; i++) {
        hb = hb->next;
      }
    }

    while (ha != nullptr) {
      if (ha == hb) {
        break;
      }
      ha = ha->next;
      hb = hb->next;
    }
    return ha;
  }
};
// @lc code=end
