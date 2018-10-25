// 283. Move Zeros
// https://leetcode.com/problems/move-zeroes/
/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
    1. You must do this in-place without making a copy of the array.
    2. Minimize the total number of operations.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                nums[index++] = nums[i];
            }
        }
        for (int i = index; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};

int main() {
    vector<int> nums{0, 1, 0, 3, 12};
    Solution().moveZeroes(nums);
    for (const int &num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
// Runtime: 12 ms, faster than 62.41% of C++ online submissions for Move Zeroes.