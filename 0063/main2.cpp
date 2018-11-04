// 63. Unique Path II
// https://leetcode.com/problems/unique-paths-ii/
/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        if (n == 0 || grid[0][0] == 1) {
            return 0;
        }
        grid[0][0] = 1;
        // i == 0
        for (int j = 1; j < n; ++j) {
            if (grid[0][j] == 1) {
                grid[0][j] = 0;
            } else {
                grid[0][j] = grid[0][j - 1];
            }
        }
        // j == 0
        for (int i = 1; i < m; ++i) {
            if (grid[i][0] == 1) {
                grid[i][0] = 0;
            } else {
                grid[i][0] = grid[i - 1][0];
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = grid[i][j - 1] + grid[i - 1][j];
                }
            }
        }
        return grid[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> grid = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0},
    };
    cout << Solution().uniquePathsWithObstacles(grid) << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths II.