/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
  bool isVowel(char ch) {
    ch = std::tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
  }
  string reverseVowels(string s) {
    std::size_t left = 0;
    std::size_t right = s.length() - 1;
    while (left < right && left < s.size() && right >= 0) {
      if (isVowel(s[left]) == false) {
        left++;
        continue;
      }
      if (isVowel(s[right]) == false) {
        right--;
        continue;
      }
      const auto tmp = s[left];
      s[left] = s[right];
      s[right] = tmp;
      left++;
      right--;
    }
    return s;
  }
};
// @lc code=end
