// 55. Jump Game
// https://leetcode.com/problems/jump-game/
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example 1:
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: [3,2,1,0,4]
Output: false

Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        if (nums.size() <= 1) {
            return true;
        }
        memo = vector<int>(nums.size(), -1);
        return __canJump(nums, nums.size() - 1);
    }

private:
    vector<int> memo;

    // 判断从索引0能够跳到index位置
    bool __canJump(const vector<int> &nums, int index) {
        if (index == 0) {
            return true;
        }
        if (memo[index] != -1) {
            return memo[index] == 1;
        }
        bool res = false;
        for (int i = index - 1; i >= 0; --i) {
            if (nums[i] >= (index - i)) {
                if (__canJump(nums, i)) {
                    res = true;
                    break;
                }
            }
        }
        memo[index] = res ? 1 : 0;
        return res;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << Solution().canJump(nums) << endl;

    nums = {3, 2, 1, 0, 4};
    cout << Solution().canJump(nums) << endl;
    return 0;
}
// Runtime: 16 ms, faster than 38.05% of C++ online submissions for Jump Game.