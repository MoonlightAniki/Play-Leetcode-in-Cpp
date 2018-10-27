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
        memo = vector<int>(nums.size(), -1);
        return tryRob(nums, 0);
    }

private:
    vector<int> memo;


    // 考虑从nums[index...nums.size-1]中偷取财物能获取的最大值
    int tryRob(vector<int> &nums, int index) {
        if (index >= nums.size()) {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        // 两种方案
        memo[index] = max(
                tryRob(nums, index + 1),//不偷取index位置的财物，考虑从nums[index+1...nums.size()-1]范围内偷取
                nums[index] + tryRob(nums, index + 2)// 偷取index位置的财物，并考虑从nums[index+2...nums.size()-1]范围内继续偷取
        );
        return memo[index];
    }
};

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << Solution().rob(nums) << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.