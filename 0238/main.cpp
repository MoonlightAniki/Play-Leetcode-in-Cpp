// 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/
/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:
Input:  [1,2,3,4]
Output: [24,12,8,6]

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int product[nums.size()];//product[index]表示nums[0...index-1]范围内元素的乘积
        product[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            product[i] = product[i - 1] * nums[i - 1];
        }
        vector<int> res(nums.size());
        int p = 1;//nums[index+1...n-1]范围内元素的乘积
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = product[i] * p;// nums[0...i-1] * nums[i+1...n-1]
            p *= nums[i];
        }
        return res;
    }
};
// Runtime: 36 ms, faster than 51.27% of C++ online submissions for Product of Array Except Self.