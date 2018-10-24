// 561. Array Partition I
// https://leetcode.com/problems/array-partition-i/
/*
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]
Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

Note:
    1. n is a positive integer, which is in the range of [1, 10000].
    2. All the integers in the array will be in the range of [-10000, 10000].
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Sort
// Time Complexity : O(nlogn)
// Space Complexity : O(1)
class Solution {
public:
    int arrayPairSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            res += nums[i];
        }
        return res;
    }
};

int main() {
    vector<int> vec = {1, 4, 3, 2};
    cout << Solution().arrayPairSum(vec) << endl;
    return 0;
}
// Runtime: 72 ms, faster than 39.36% of C++ online submissions for Array Partition I.