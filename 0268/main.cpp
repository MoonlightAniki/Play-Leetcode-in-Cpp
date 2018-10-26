// 268. Missing Number
// https://leetcode.com/problems/missing-number/
/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:
Input: [3,0,1]
Output: 2

Example 2:
Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        long long sum = n * (n + 1) / 2;
        for (const int &i : nums) {
            sum -= i;
        }
        return (int) sum;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 16 ms, faster than 89.25% of C++ online submissions for Missing Number.