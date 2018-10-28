// 204. Count Primes
// https://leetcode.com/problems/count-primes/
/*
Count the number of prime numbers less than a non-negative number, n.

Example:
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> notPrime(n, false);
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (!notPrime[i]) {
                ++res;
                for (int j = 2 * i; j < n; j += i) {
                    notPrime[j] = true;
                }
            }
        }
        return res;
    }
};

int main() {
    cout << Solution().countPrimes(10) << endl;
    cout << Solution().countPrimes(2) << endl;
    cout << Solution().countPrimes(12) << endl;
    return 0;
}
// Runtime: 24 ms, faster than 69.31% of C++ online submissions for Count Primes.