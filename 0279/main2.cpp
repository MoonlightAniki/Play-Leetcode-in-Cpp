// 279. Perfect Squares
// https://leetcode.com/problems/perfect-squares/
/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        memo = vector<int>(n + 1, -1);
        return helper(n);
    }

private:
    vector<int> memo;

    int helper(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        int res = n;
        for (int i = 1; i * i <= n; ++i) {
            res = min(res, 1 + helper(n - i * i));
        }
        memo[n] = res;
        return res;
    }
};

int main() {
    cout << Solution().numSquares(13) << endl;
    cout << Solution().numSquares(12) << endl;
    return 0;
}
// Runtime: 84 ms, faster than 30.17% of C++ online submissions for Perfect Squares.