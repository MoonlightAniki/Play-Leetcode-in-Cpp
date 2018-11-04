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
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int n = nums.size();
        assert(n >= 3);
        sort(nums.begin(), nums.end());
        int diff = abs(nums[0] + nums[1] + nums[2] - target);
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n; ++i) {
            // 问题转化为在 nums[i+1...n-1] 范围内找两个元素的和最接近 target-nums[i]
            int l = i + 1;
            int r = n - 1;
            int t = target - nums[i];
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum == t) {
                    return nums[i] + sum;
                } else {
                    if (abs(nums[i] + sum - target) < diff) {
                        diff = abs(nums[i] + sum - target);
                        res = nums[i] + sum;
                    }
                    if (sum < t) {
                        ++l;
                    } else {
                        --r;
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
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for 3Sum Closest.