// 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/
/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2

Note:
    The length of the array is in range [1, 20,000].
    The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        vector<int> sums(nums.size() + 1, 0);// sums[index]表示nums[0...index-1]范围内元素的和
        for (int i = 1; i <= nums.size(); ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        int res = 0;
        for (int i = nums.size(); i > 0; --i) {
            for (int j = 0; j < i; ++j) {
                if (sums[i] - sums[j] == k) {
                    ++res;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << Solution().subarraySum(nums, 2) << endl;

    nums = {1, 1, 0};
    cout << Solution().subarraySum(nums, 1) << endl;
    return 0;
}
// Runtime: 348 ms, faster than 15.38% of C++ online submissions for Subarray Sum Equals K.