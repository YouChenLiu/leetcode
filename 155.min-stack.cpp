/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <algorithm>
#include <stack>
#include <utility>
class MinStack {

  std::stack<std::pair<int, int>> stack;

public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int val) {
    const auto topMin = stack.empty() ? val : stack.top().second;
    stack.push({val, std::min(val, topMin)});
  }

  void pop() { stack.pop(); }

  int top() { return stack.top().first; }

  int getMin() { return stack.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
