// 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/
/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:
Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Note:
There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i] && res[j] + 1 > res[i]) {
                    res[i] = res[j] + 1;
                }
            }
        }
        int ret = 1;
        for (int i = 0; i < res.size(); ++i) {
            ret = max(ret, res[i]);
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << Solution().lengthOfLIS(nums) << endl;
    return 0;
}
// Runtime: 24 ms, faster than 26.23% of C++ online submissions for Longest Increasing Subsequence.