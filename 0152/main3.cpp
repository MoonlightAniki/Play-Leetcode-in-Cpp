// 152. Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/
/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        assert(nums.size() > 0);
        int res = nums[0];
        int maxEndingHere = res;
        int minEndingHere = res;
        for (int i = 1; i < nums.size(); ++i) {
            // 如果nums[i]是负数,nums[i]乘以最小值得到最大值，乘以最大值得到最小值
            if (nums[i] < 0) {
                swap(minEndingHere, maxEndingHere);
            }
            minEndingHere = min(minEndingHere * nums[i], nums[i]);
            maxEndingHere = max(maxEndingHere * nums[i], nums[i]);
            res = max(res, maxEndingHere);
        }
        return res;
    }
//
//private:
//    void swap(int &a, int &b) {
//        int temp = a;
//        a = b;
//        b = temp;
//    }
};

int main() {
    vector<int> nums = {3, -1, 4};
    int res = Solution().maxProduct(nums);
    cout << res << endl;
    return 0;
}
// Runtime: 4 ms, faster than 99.08% of C++ online submissions for Maximum Product Subarray.