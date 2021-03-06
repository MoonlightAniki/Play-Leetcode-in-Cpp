// 287. Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/
// Time: 2018-11-07
/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one
duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:
Input: [1,3,4,2,2]
Output: 2

Example 2:
Input: [3,1,3,4,2]
Output: 3

Note:
    You must not modify the array (assume the array is read only).
    You must use only constant, O(1) extra space.
    Your runtime complexity should be less than O(n2).
    There is only one duplicate number in the array, but it could be repeated more than once.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        if (nums.size() <= 1) {
            return -1;
        }
        int slow = nums[0];//每次移动一步
        int fast = nums[nums[0]];//每次移动2步
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // 从0移动到entry point的距离等于从slow移动到entry point的距离
        int entry = 0;
        while (entry != slow) {
            entry = nums[entry];
            slow = nums[slow];
        }
        return entry;
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << Solution().findDuplicate(nums) << endl;

    nums = {3, 1, 3, 4, 2};
    cout << Solution().findDuplicate(nums) << endl;
    return 0;
}
// Runtime: 8 ms, faster than 83.02% of C++ online submissions for Find the Duplicate Number.