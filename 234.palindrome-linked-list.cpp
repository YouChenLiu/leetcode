/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
  bool isPalindrome(ListNode *head) {
    std::vector<int> vec;
    while (head != nullptr) {
      vec.push_back(head->val);
      head = head->next;
    }

    for (int i = 0, j = vec.size() - 1; i < j; i++, j--) {
      if (vec[i] != vec[j]) {
        return false;
      }
    }
    return true;

    // this solution is a pratice for me
    // slow as above one, keep above solution
    /*
    // get the middle node
    auto slow = head;
    auto fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // push values to stack from middle
    std::stack<int> stack;
    while (slow != nullptr) {
      stack.push(slow->val);
      slow = slow->next;
    }

    // validate each val from head and stack
    while (!stack.empty()) {
      const auto &val = stack.top();
      if (head->val != val) {
        return false;
      }
      stack.pop();
      head = head->next;
    }
    return true;
    */
  }
};
// @lc code=end
