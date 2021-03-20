/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <map>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    const std::map<char, char> map{{'(', ')'}, {'[', ']'}, {'{', '}'}};
    std::stack<char> stack;
    auto last = '\0';
    for (std::size_t i = 0; i < s.length(); i++) {
      const auto current = s[i];

      if (current == '(' || current == '[' || current == '{' || stack.empty()) {
        stack.push(current);
        last = current;
        continue;
      }

      const auto it = map.find(last);
      if (it == map.end()) {
        return false;
      }

      if (it->second == current) {
        stack.pop();
        if (!stack.empty()) {
          last = stack.top();
        }
      } else {
        return false;
      }
    }
    return stack.empty();
  }
};
// @lc code=end
