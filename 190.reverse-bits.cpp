/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
#include <cstdint>
#include <deque>
class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    // use deque to reverse order, too slow and too much memory
    /*
    std::deque<int> deque;
    for (int i = 0; i < 32; i++) {
      deque.push_back(n & 0x01);
      n >>= 1;
    }
    uint32_t ans = 0;
    while (!deque.empty()) {
      const auto &bit = deque.front();
      deque.pop_front();
      ans <<= 1;
      ans |= bit;
    }
    return ans;
    */
    uint32_t maskL = 0x80000000;
    uint32_t maskR = 0x00000001;
    for (int i = 0; i < 16; i++) {
      uint32_t combined = maskL | maskR;
      const auto left = n & maskL;
      const auto right = n & maskR;
      if ((left != 0 && right == 0) || (left == 0 && right != 0)) {
        const auto combined = maskL | maskR;
        n ^= combined;
      }
      maskL >>= 1;
      maskR <<= 1;
    }
    return n;
  }
};
// @lc code=end
