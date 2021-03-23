/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <vector>
class Solution {
public:
  // original
  //   std::unordered_set<int> primes{2};
  //   int countPrimes(int n) {
  //     if (n <= 2) {
  //       return 0;
  //     }
  //     for (int i = 3; i < n; i++) {
  //       bool isPrime = true;
  //       for (const auto &prime : primes) {
  //         const auto upper = std::floor(std::sqrt(i));
  //         if ((prime < upper) && (i % prime == 0)) {
  //           isPrime = false;
  //           break;
  //         }
  //       }
  //       if (isPrime) {
  //         primes.insert(i);
  //       }
  //     }
  //     return primes.size();
  //   }

  // sieve of Eratosthenes
  // https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
  int countPrimes(int n) {
    if (n <= 2) {
      return 0;
    }
    std::vector<bool> isPrimes(n, true);
    isPrimes[0] = isPrimes[1] = false;
    for (int i = 2; i <= static_cast<int>(std::sqrt(n)); i++) {
      if (!isPrimes[i]) {
        continue;
      }
      for (int j = 2 * i; j <= n; j += i) {
        isPrimes[j] = false;
      }
    }
    return std::count_if(isPrimes.begin() + 2, isPrimes.end(),
                         [](bool b) { return b; });
  }
};
// @lc code=end
