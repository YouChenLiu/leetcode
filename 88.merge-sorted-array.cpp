/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    if (m == 0) {
      nums1 = nums2;
      return;
    }
    if (n == 0) {
      return;
    }
    std::vector<int> merged(m + n);
    int mi = 0;
    int ni = 0;
    int idx = 0;
    while (idx < m + n) {
      if (mi < m && ni < n) {
        const auto &currentM = nums1[mi];
        const auto &currentN = nums2[ni];
        if (currentM < currentN) {
          merged[idx] = currentM;
          mi++;
        } else {
          merged[idx] = currentN;
          ni++;
        }
      } else {
        if (mi == m) {
          merged[idx] = nums2[ni];
          ni++;
        } else {
          merged[idx] = nums1[mi];
          mi++;
        }
      }
      idx++;
    }

    nums1 = merged;
  }
};
// @lc code=end
