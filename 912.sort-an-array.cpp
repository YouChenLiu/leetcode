/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
  void swap(int &lhs, int &rhs) {
    const auto tmp = lhs;
    lhs = rhs;
    rhs = tmp;
  }
  int partition(std::vector<int> &arr, int l, int r, int pivot) {
    const auto pivotVal = arr[pivot];
    swap(arr[pivot], arr[r]);
    auto idx = l;
    for (int i = l; i < r; i++) {
      if (arr[i] <= pivotVal) {
        swap(arr[idx], arr[i]);
        idx++;
      }
    }
    swap(arr[r], arr[idx]);
    return idx;
  }
  void quickSort(std::vector<int> &arr, int l, int r) {
    if (l >= r) {
      return;
    }
    const auto median = (l + r) / 2;
    const auto pivotIdx = partition(arr, l, r, median);
    quickSort(arr, l, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, r);
  }
  vector<int> sortArray(vector<int> &nums) {
    auto arr = nums;
    quickSort(arr, 0, arr.size() - 1);
    return arr;
  }
};
// @lc code=end
