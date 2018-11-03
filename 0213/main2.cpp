// 213. House Robber II
// https://leetcode.com/problems/house-robber-ii/
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }

private:
    int rob(vector<int> &nums, int start, int end) {
        int preMax = nums[start];
        int curMax = max(preMax, nums[start + 1]);
        for (int i = start + 2; i <= end; ++i) {
            int temp = curMax;
            curMax = max(curMax,//不偷取i位置处的财物
                         preMax + nums[i]);//偷取i位置处的财物
            preMax = temp;
        }
        return curMax;
    }
};
// Runtime: 4 ms, faster than 19.97% of C++ online submissions for House Robber II.