/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    std::stack<int> stack;
    for (const auto &val : digits) {
      stack.push(val);
    }

    std::vector<int> result;
    result.reserve(digits.size());
    int carry = 1;
    while (!stack.empty()) {
      auto val = stack.top() + carry;
      carry = 0;
      if (val >= 10) {
        val = 0;
        carry = 1;
      }
      result.insert(result.begin(), val);
      stack.pop();
    }
    if (carry != 0) {
      result.insert(result.begin(), carry);
    }
    return result;
  }
};
// @lc code=end
