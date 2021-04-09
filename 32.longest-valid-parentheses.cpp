/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    int max = 0;
    int answer = 0;
    std::stack<char> stack;
    for (const auto &ch : s) {
      if (stack.empty()) {
        stack.push(ch);
        continue;
      }
      if (!stack.empty() && stack.top() == '(' && ch == ')') {
        stack.pop();
        answer += 2;
        continue;
      }
      if (!stack.empty() && stack.top() == ')' && ch == ')') {
        max = std::max(max, answer);
        answer = 0;
        stack = std::stack<char>();
        continue;
      }
      stack.push(ch);
    }
    return std::max(max, answer);
  }
};
// @lc code=end
