/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
  string addBinary(string a, string b) {
    const auto length = std::min(a.length(), b.length());
    auto bitA = a.rbegin();
    auto bitB = b.rbegin();
    int carry = 0;
    std::stack<char> stack;
    for (std::size_t i = 0; i < length; i++) {
      const auto valA = *bitA - '0';
      const auto valB = *bitB - '0';
      const auto sum = valA + valB + carry;
      carry = (sum & 0x02) >> 1;
      stack.push(sum & 0x01);
      bitA++;
      bitB++;
    }

    auto it = bitA != a.rend() ? bitA : bitB;
    auto end = bitA != a.rend() ? a.rend() : b.rend();
    while (it != end) {
      const auto sum = *it - '0' + carry;
      carry = (sum & 0x02) >> 1;
      stack.push(sum & 0x01);
      it++;
    }
    if (carry != 0) {
      stack.push(1);
    }

    std::string result;
    while (!stack.empty()) {
      result.push_back(stack.top() + '0');
      stack.pop();
    }

    return result;
  }
};
// @lc code=end
