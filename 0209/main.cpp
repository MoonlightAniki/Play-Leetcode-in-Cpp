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

// Sum Prefix + Binary Search
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        vector<int> sums(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        int res = nums.size() + 1;
        int l = 0;//sums[r] - sums[l] >= s ==> sum[r] >= s + sums[l]
        for (l = 0; l < (int) nums.size() - 1; ++l) {
            auto r_bound = lower_bound(sums.begin(), sums.end(), s + sums[l]);
            if (r_bound != sums.end()) {
                int r = r_bound - sums.begin();
                res = min(res, r - l);
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
// Runtime: 16 ms, faster than 13.41% of C++ online submissions for Minimum Size Subarray Sum.