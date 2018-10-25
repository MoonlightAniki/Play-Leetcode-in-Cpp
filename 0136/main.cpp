// 136. Single Number
// https://leetcode.com/problems/single-number/
/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,1]
Output: 1

Example 2:
Input: [4,1,2,1,2]
Output: 4
 */
#include <iostream>
#include <vector>

using namespace std;
// 使用了异或(^)的两个性质：
// 1. n ^ n = 0
// 2. 0 & n = n
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int res = 0;
        for (const int &num : nums) {
            res ^= num;
        }
        return res;
    }
};

int main() {
//    vector<int> nums{2, 2, 1};
    vector<int> nums{4, 1, 2, 1, 2};
    cout << Solution().singleNumber(nums) << endl;
    return 0;
}
// Runtime: 8 ms, faster than 98.73% of C++ online submissions for Single Number.