// 581. Shortest Unsorted Continuous Subarray
// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:
    Then length of the input array is in range [1, 10,000].
    The input array may contain duplicates, so ascending order here means <=.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        vector<int> aux(nums);
        sort(aux.begin(), aux.end());
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != aux[i]) {
                break;
            }
            ++i;
        }
        if (i == nums.size()) {
            return 0;
        }
        int j = nums.size() - 1;
        while (j >= 0) {
            if (nums[j] != aux[j]) {
                break;
            }
            --j;
        }
        return j - i + 1;
    }
};
// Runtime: 32 ms, faster than 65.98% of C++ online submissions for Shortest Unsorted Continuous Subarray.