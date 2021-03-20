/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> getRow(int rowIndex) {
    std::vector<std::vector<int>> pascal{{1}};
    for (int row = 1; row <= rowIndex; row++) {
      std::vector<int> current(row + 1);
      current[0] = current[current.size() - 1] = 1;
      for (std::size_t col = 1; col < current.size() - 1; col++) {
        const auto &upper = pascal[row - 1];
        current[col] = upper[col - 1] + upper[col];
      }
      pascal.push_back(current);
    }
    return pascal[rowIndex];
  }
};
// @lc code=end
