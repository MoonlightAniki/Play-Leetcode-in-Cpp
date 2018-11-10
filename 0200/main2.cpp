// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/
// Time: 2018-11-10
/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input:
11110
11010
11000
00000
Output: 1

Example 2:
Input:
11000
11000
00100
00011
Output: 3
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/// Floodfill - DFS
/// Non-recursion implementation
///
/// Time Complexity: O(n*m)
/// Space Complexity: O(n*m)
class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        if (n == 0) return 0;
        for (int i = 0; i < m; ++i) {
            visited.push_back(vector<bool>(n, false));
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }


private:
    int m, n;

    int d[4][2] = {
            {-1, 0},//向上
            {0,  1},//向右
            {1,  0},//向下
            {0,  -1},//向左
    };

    vector<vector<bool>> visited;

    bool inArea(int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }

    void dfs(const vector<vector<char>> &grid, int row, int col) {
        stack<pair<int, int>> s;
        s.push(make_pair(row, col));
        visited[row][col] = true;
        while (!s.empty()) {
            pair<int, int> node = s.top();
            s.pop();

            for (int i = 0; i < 4; ++i) {
                int newRow = node.first + d[i][0];
                int newCol = node.second + d[i][1];
                if (inArea(newRow, newCol) && !visited[newRow][newCol] && grid[newRow][newCol] == '1') {
                    s.push(make_pair(newRow, newCol));
                    visited[newRow][newCol] = true;
                }
            }
        }
    }
};

int main() {
    vector<vector<char>> grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'},
    };
    cout << Solution().numIslands(grid) << endl;


    grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'},
    };
    cout << Solution().numIslands(grid) << endl;
    return 0;
}
// Runtime: 16 ms, faster than 26.79% of C++ online submissions for Number of Islands.