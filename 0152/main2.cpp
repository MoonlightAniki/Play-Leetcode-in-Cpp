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
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            int product = 1;
            for (int j = i; j < nums.size(); ++j) {
                product *= nums[j];
                res = max(res, product);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {-2, 3, -1};
    int res = Solution().maxProduct(nums);
    cout << res << endl;
    return 0;
}
// Runtime: 364 ms, faster than 1.99% of C++ online submissions for Maximum Product Subarray.