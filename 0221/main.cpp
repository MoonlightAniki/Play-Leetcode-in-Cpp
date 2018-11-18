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
        for (int w = min(m, n); w > 0; --w) {
            for (int i = 0; i + w <= m; ++i) {
                for (int j = 0; j + w <= n; ++j) {
                    bool exists = true;
                    for (int u = 0; exists && u < w; ++u) {
                        for (int v = 0; exists && v < w; ++v) {
                            if (matrix[i + u][j + v] == '0') {
                                exists = false;
                            }
                        }
                    }
                    if (exists) {
                        return w * w;
                    }
                }
            }
        }
        return 0;
    }
};
// Runtime: 112 ms, faster than 1.84% of C++ online submissions for Maximal Square.