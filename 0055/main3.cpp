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
        int i = 0;
        // max_reach表示在索引i处能跳到的最远的位置
        for (int max_reach = 0; i < nums.size() && i <= max_reach; ++i) {
            max_reach = max(max_reach, i + nums[i]);
        }
        return i == nums.size();
    }
};


int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << Solution().canJump(nums) << endl;

    nums = {3, 2, 1, 0, 4};
    cout << Solution().canJump(nums) << endl;
    return 0;
}
// Runtime: 8 ms, faster than 98.75% of C++ online submissions for Jump Game.