// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/
/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example:
Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.

Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int l = 0;
        int r = -1;
        int sum = 0;//nums[l...r]范围内元素的和
        int res = nums.size() + 1;
        while (l < nums.size()) {
            if (r + 1 < nums.size() && sum < s) {
                sum += nums[++r];
            } else {
                sum -= nums[l++];
            }
            if (sum >= s) {
                res = min(res, r - l + 1);
            }
        }
        if (res == nums.size() + 1) {
            return 0;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << Solution().minSubArrayLen(7, nums) << endl;

    nums = {2, 3, 1};
    cout << Solution().minSubArrayLen(7, nums) << endl;

    nums = {1, 2, 3, 4, 5};
    cout << Solution().minSubArrayLen(15, nums) << endl;
    return 0;
}
// Runtime: 8 ms, faster than 98.60% of C++ online submissions for Minimum Size Subarray Sum.