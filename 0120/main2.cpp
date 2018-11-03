// 120. Triangle
// https://leetcode.com/problems/triangle/
/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        res = INT_MAX;
        int path = 0;
        helper(triangle, 0, 0, path);
        return res;
    }

private:
    int res;

    void helper(vector<vector<int>> &triangle, int row, int col, int &path) {
        if (row == triangle.size() - 1) {
            path += triangle[row][col];
            res = min(res, path);
            path -= triangle[row][col];
            return;
        }
        path += triangle[row][col];
        helper(triangle, row + 1, col, path);
        helper(triangle, row + 1, col + 1, path);
        path -= triangle[row][col];
    }
};

int main() {
    vector<vector<int>> triangle = {
            {2},
            {3, 4},
            {6, 5, 7},
            {4, 1, 8, 3}
    };
    cout << Solution().minimumTotal(triangle) << endl;
    return 0;
}
// Time Limit Exceeded