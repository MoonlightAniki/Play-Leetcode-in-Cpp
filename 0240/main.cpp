// 240. Search a 2D Matrix II
// https://leetcode.com/problems/search-a-2d-matrix-ii/
// Time: 2018-11-09
/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

Example:
Consider the following matrix:
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.
Given target = 20, return false.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int r = -1;
        for (int j = 0; j < n && matrix[0][j] <= target; ++j) {
            if (matrix[0][j] == target) {
                return true;
            } else {
                r = j;
            }
        }
        if (r == -1) return false;
        for (int i = 1; i < m && matrix[i][0] <= target; ++i) {
            if (binarySearch(matrix[i], 0, r, target) != -1) {
                return true;
            }
        }
        return false;
    }

private:
    int binarySearch(const vector<int> &nums, int l, int r, const int &target) {
        if (l > r) {
            return -1;
        }
        int mid = l + (r - l) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target < nums[mid]) {
            return binarySearch(nums, l, mid - 1, target);
        } else {
            return binarySearch(nums, mid + 1, r, target);
        }
    }
};
// Runtime: 128 ms, faster than 16.90% of C++ online submissions for Search a 2D Matrix II.