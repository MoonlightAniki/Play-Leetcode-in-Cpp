// 494. Target Sum
// https://leetcode.com/problems/target-sum/
/*
Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
There are 5 ways to assign symbols to make the sum of nums be target 3.

Note:
    The length of the given array is positive and will not exceed 20.
    The sum of elements in the given array will not exceed 1000.
    Your output answer is guaranteed to be fitted in a 32-bit integer.
 */

#include <iostream>
#include <vector>

using namespace std;

// 问题等价于nums的一个子序列P的和减去剩余元素的子序列Q的和等于S
// ==> sum(P) - sum(Q) = S
// ==> sum(P) - sum(Q) + sum(P) + sum(Q) = S + sum(P) + sum(Q)
// ==> 2*sum(P) = S + sum(nums)
// ==> sum(P) = (S + sum(nums)) / 2, S + sum(nums) 必须为偶数
// 等价于在找 和等于 (S + sum(nums)) / 2 的子序列的个数
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        int sum = 0;
        for (const int &num : nums) {
            sum += num;
        }
        if (sum + S < 0 || (sum + S) % 2 == 1 || sum < S) {
            return 0;
        }
        int target = (sum + S) / 2;
        return subsetSum(nums, target);
    }


private:
    int subsetSum(vector<int> &nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));//dp[i][j]表示考虑用nums[0...i]填充容量为j的背包的方法数
        // i == 0
        for (int j = 0; j <= target; ++j) {
            if (j == 0) {
                dp[0][j] += 1;
            }
            if (j == nums[0]) {
                dp[0][j] += 1;
            }
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <= target; ++j) {
                // 不将nums[i]放入背包中
                dp[i][j] += dp[i - 1][j];

                // 将nums[i]放入背包中
                if (j - nums[i] >= 0) {
                    dp[i][j] += dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp[nums.size() - 1][target];
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << Solution().findTargetSumWays(nums, 3) << endl;

    nums = {1, 0};
    cout << Solution().findTargetSumWays(nums, 1) << endl;

    nums = {0, 0, 1};
    cout << Solution().findTargetSumWays(nums, 1) << endl;
    return 0;
}
// Runtime: 4 ms, faster than 99.81% of C++ online submissions for Target Sum.