// 566. Reshape the Matrix
// https://leetcode.com/problems/reshape-the-matrix/
/*
n MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.
You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.
The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.
If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input:
nums =
[[1,2],
 [3,4]]
r = 1, c = 4
Output:
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.

Example 2:
Input:
nums =
[[1,2],
 [3,4]]
r = 2, c = 4
Output:
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        vector<vector<int>> res(r, vector<int>(c, 0));
        int total = r * c;

        int count = 0;
        for (const vector<int> &v : nums) {
            for (const int &num : v) {
                res[count / c][count % c] = num;
                ++count;
                if (count > total) {
                    return nums;
                }
            }
        }
        if (count != total) {
            return nums;
        }
        return res;
    }
};

int main() {
    vector<vector<int>> nums{
            {1,  2,  3,  4},
            {5,  6,  7,  8},
            {9,  10, 11, 12},
    };
    vector<vector<int>> res = Solution().matrixReshape(nums, 4, 3);
    for (const vector<int> &v : res) {
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " ";

            if (i == v.size() - 1) {
                cout << endl;
            }
        }
    }
    return 0;
}
// Runtime: 44 ms, faster than 31.06% of C++ online submissions for Reshape the Matrix.