// 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/
// Time: 2018-11-04
/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int diff = INT_MAX;
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (abs(sum - target) < diff) {
                        diff = abs(sum - target);
                        res = sum;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    cout << Solution().threeSumClosest(nums, 1) << endl;
    return 0;
}
// Runtime: 188 ms, faster than 5.24% of C++ online submissions for 3Sum Closest.