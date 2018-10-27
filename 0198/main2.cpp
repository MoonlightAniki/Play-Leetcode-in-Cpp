// 198. House Robber
// https://leetcode.com/problems/house-robber/
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and
it will automatically contact the police if two adjacent houses were broken into on the same night. Given a list of
non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob
tonight without alerting the police.

Example 1:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:
Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int dp[n + 1];//dp[index]表示考虑从nums[index...n-1]范围内偷取财物的最大值
        dp[n] = 0;
        dp[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
        return dp[0];
    }
};

int main() {
//    vector<int> nums = {2, 7, 9, 3, 1};
    vector<int> nums = {1};
    cout << Solution().rob(nums) << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.