// 454. 4Sum II
// https://leetcode.com/problems/4sum-ii/
/*
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:
Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        unordered_map<int, int> records;
        for (const int &a : A) {
            for (const int &b : B) {
                ++records[a + b];
            }
        }
        int res = 0;
        for (const int &c : C) {
            for (const int &d : D) {
                res += records[0 - c - d];
            }
        }
        return res;
    }
};
// Runtime: 144 ms, faster than 65.69% of C++ online submissions for 4Sum II.