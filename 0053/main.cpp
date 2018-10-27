// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/
/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> sum(nums.size() + 1);//sum[index]为nums[0...index-1]范围内元素的和
        for (int i = 1; i < sum.size(); ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        // 这部分参考 121 号问题
        int curMinSum = sum[0];
        int res = 0x80000000;// int最小值
        for (int i = 1; i < sum.size(); ++i) {
            res = max(res, sum[i] - curMinSum);
            curMinSum = min(curMinSum, sum[i]);
        }
        return res;
    }
};

int main() {
//    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums = {1, 2};
//    vector<int> nums = {-1};

    cout << Solution().maxSubArray(nums) << endl;
    return 0;
}
// Runtime: 8 ms, faster than 66.28% of C++ online submissions for Maximum Subarray.