/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */
#include <string>

using namespace std;

// @lc code=start
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  string intToRoman(int num) {
    std::string ans;
    std::vector<int> digits{1000, 900, 500, 400, 100, 90, 50,
                            40,   10,  9,   5,   4,   1};
    std::vector<string> table{"M",  "CM", "D",  "CD", "C",  "XC", "L",
                              "XL", "X",  "IX", "V",  "IV", "I"};
    for (std::size_t i = 0; i < digits.size(); i++) {
      while (num >= digits[i]) {
        // std::cout << digits[i] << " " << table[i] << std::endl;
        num -= digits[i];
        ans.append(table[i]);
      }
    }
    return ans;
  }
};
// @lc code=end
