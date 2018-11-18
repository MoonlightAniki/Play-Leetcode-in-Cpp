// 221. Maximal Square
// https://leetcode.com/problems/maximal-square/
/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:
Input:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Output: 4
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        int ret = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    }
                    ret = max(ret, dp[i][j]);
                }
            }
        }
        return ret * ret;
    }
};

int main(void) {
    vector<vector<char>> matrix = {{'1', '0'},
                                   {'0', '1'}};
    cout << Solution().maximalSquare(matrix) << endl;
    return 0;
}
// Runtime: 12 ms, faster than 98.16% of C++ online submissions for Maximal Square.