// 343. Integer Break
// https://leetcode.com/problems/integer-break/
/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers.
Return the maximum product you can get.

Example 1:
Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:
Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        memo = vector<int>(n + 1, -1);
        return breakInteger(n);
    }

private:
    vector<int> memo;

    int breakInteger(int n) {
        if (n <= 2) {
            return 1;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        int res = 0;
        for (int i = 1; i < n; ++i) {
            res = max3(res, i * (n - i), breakInteger(i) * (n - i));
        }
        memo[n] = res;
        return res;
    }

    int max3(int a, int b, int c) {
        return max(max(a, b), c);
    }
};

int main() {
    cout << Solution().integerBreak(10) << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Integer Break.