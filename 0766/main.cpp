// 766. Toeplitz Matrix
// https://leetcode.com/problems/toeplitz-matrix/
/*
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
Now given an M x N matrix, return True if and only if the matrix is Toeplitz.


Example 1:
Input:
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]
Output: True
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.

Example 2:
Input:
matrix = [
  [1,2],
  [2,2]
]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.

Note:
    matrix will be a 2D array of integers.
    matrix will have a number of rows and columns in range [1, 20].
    matrix[i][j] will be integers in range [0, 99].
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        m = matrix.size();
        n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            int base = matrix[i][0];
            for (int u = i + 1, v = 1; inArea(u, v); ++u, ++v) {
                if (matrix[u][v] != base) {
                    return false;
                }
            }
        }

        for (int j = 1; j < n; ++j) {
            int base = matrix[0][j];
            for (int u = 1, v = j + 1; inArea(u, v); ++u, ++v) {
                if (matrix[u][v] != base) {
                    return false;
                }
            }
        }

        return true;

    }

private:
    int m, n;

    bool inArea(int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
};

int main() {
    vector<vector<int>> matrix{
            {1, 2, 3, 4},
            {5, 1, 2, 3},
            {9, 5, 1, 2},
    };
    cout << Solution().isToeplitzMatrix(matrix) << endl;
    return 0;
}
// Runtime: 8 ms, faster than 98.90% of C++ online submissions for Toeplitz Matrix.