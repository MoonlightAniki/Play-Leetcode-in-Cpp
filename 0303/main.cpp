// 303. Range Sum Query - Immutable
// https://leetcode.com/problems/range-sum-query-immutable/
/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
    1. You may assume that the array does not change.
    2. There are many calls to sumRange function.
 */

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> sums;

public:
    NumArray(vector<int> nums) {
        sums = vector<int>(nums.size() + 1, 0);//sums[index]表示nums[0...index-1]范围内元素的和
        for (int i = 1; i < sums.size(); ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray a = NumArray(nums);
    cout << a.sumRange(0, 2) << endl;
    cout << a.sumRange(2, 5) << endl;
    cout << a.sumRange(0, 5) << endl;
    return 0;
}
// Runtime: 124 ms, faster than 73.70% of C++ online submissions for Range Sum Query - Immutable.