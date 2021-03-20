/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> pascal{{1}};
    for (int row = 1; row < numRows; row++) {
      std::vector<int> current(row + 1);
      current[0] = current[current.size() - 1] = 1;
      for (std::size_t col = 1; col < current.size() - 1; col++) {
        const auto &upper = pascal[row - 1];
        current[col] = upper[col - 1] + upper[col];
      }
      pascal.push_back(current);
    }
    return pascal;
  }
};
// @lc code=end
