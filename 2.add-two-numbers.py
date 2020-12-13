#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        node1 = l1
        node2 = l2
        carry = 0
        ansHead = ListNode()
        lastAns = ansHead
        while True:
            print(node1)
            stopCondiction = lastAns is None
            if stopCondiction is True:
                break

            if node1 is None:
                node1 = ListNode()
            if node2 is None:
                node2 = ListNode()

            sum = node1.val + node2.val + carry
            carry = sum // 10
            val = sum % 10
            lastAns.val = val
            if node1.next is not None or node2.next is not None or carry != 0:
                lastAns.next = ListNode()
            node1 = node1.next
            node2 = node2.next
            lastAns = lastAns.next

        return ansHead


# @lc code=end
if __name__ == "__main__":
    l1Val = [2, 4, 3]
    l2Val = [5, 6, 4]

    l1Head = ListNode()
    l1 = l1Head
    for i in range(0, len(l1Val)):
        l1.val = l1Val[i]
        if i != len(l1Val) - 1:
            l1.next = ListNode()
            l1 = l1.next

    l2Head = ListNode()
    l2 = l2Head
    for i in range(0, len(l1Val)):
        l2.val = l2Val[i]
        if i != len(l2Val) - 1:
            l2.next = ListNode()
            l2 = l2.next

    sol = Solution()
    ans = sol.addTwoNumbers(l1Head, l2Head)
    pass
