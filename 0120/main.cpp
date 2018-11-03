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

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        if (triangle.size() == 0) {
            return 0;
        }
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                } else if (j == triangle[i].size() - 1) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
            }
        }
        vector<int> bottom = triangle[triangle.size() - 1];
        int res = bottom[0];
        for (int j = 1; j < bottom.size(); ++j) {
            res = min(res, bottom[j]);
        }
        return res;
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
// Runtime: 4 ms, faster than 99.37% of C++ online submissions for Triangle.