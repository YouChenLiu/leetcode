#include <string>
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    const auto str = std::to_string(x);
    for (int i = 0; i < str.length() / 2; i++) {
      const auto lhs = i;
      const auto rhs = str.length() - 1 - i;
      if (str[lhs] != str[rhs]) {
        return false;
      }
    }

    return true;
  }
};