// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/
/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
    Each of the array element will not exceed 100.
    The array size will not exceed 200.

Example 1:
Input: [1, 5, 11, 5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: [1, 2, 3, 5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (const int &num : nums) {
            sum += num;
        }
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        return subsetSum(nums, target);
    }

private:
    bool subsetSum(vector<int> &nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= 0; --j) {
                if (j - nums[i] >= 0) {
                    dp[j] += dp[j - nums[i]];
                }
            }
            if (dp[target] > 0) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout << Solution().canPartition(nums) << endl;

    nums = {1, 2, 3, 5};
    cout << Solution().canPartition(nums) << endl;

    nums = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
            100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
            100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
            100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
            100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
    cout << nums.size() << endl;
    cout << Solution().canPartition(nums) << endl;
    return 0;
}
// Runtime: 8 ms, faster than 84.86% of C++ online submissions for Partition Equal Subset Sum.