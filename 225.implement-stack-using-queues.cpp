/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
#include <deque>
class MyStack {
  std::deque<int> deque;

public:
  /** Initialize your data structure here. */
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x) { deque.push_back(x); }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int val = deque.back();
    deque.pop_back();
    return val;
  }

  /** Get the top element. */
  int top() { return deque.back(); }

  /** Returns whether the stack is empty. */
  bool empty() { return deque.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
