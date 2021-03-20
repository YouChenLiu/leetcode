#include <string>

using namespace std;

class Solution {
public:
  int cvt(char c) {
    int val = 0;
    switch (c) {
    case 'I':
      val = 1;
      break;
    case 'V':
      val = 5;
      break;
    case 'X':
      val = 10;
      break;
    case 'L':
      val = 50;
      break;
    case 'C':
      val = 100;
      break;
    case 'D':
      val = 500;
      break;
    case 'M':
      val = 1000;
      break;
    }
    return val;
  }
  int romanToInt(string s) {
    auto last = s[0];
    auto lastVal = cvt(last);
    int sum = cvt(last);

    for (std::size_t i = 1; i < s.length(); i++) {
      const auto current = s[i];
      const auto currentVal = cvt(current);
      sum += currentVal;
      if (lastVal < currentVal) {
        sum -= 2 * lastVal;
      }
      last = current;
      lastVal = currentVal;
    }

    return sum;
  }
};