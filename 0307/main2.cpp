// 307. Range Sum Query -- Mutable
// https://leetcode.com/problems/range-sum-query-mutable/
/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.

Example:
Given nums = [1, 3, 5]
sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
 */

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> sum;//sum[index]表示nums[0...index-1]范围内元素的和
    vector<int> data;
public:

    NumArray(vector<int> nums) {
        for (const int &num : nums) {
            data.push_back(num);
        }
        sum = vector<int>(data.size() + 1, 0);
        for (int i = 1; i < sum.size(); ++i) {
            sum[i] = sum[i - 1] + data[i - 1];
        }
    }

    void update(int index, int val) {
        int diff = val - data[index];
        data[index] = val;
        for (int i = index + 1; i < sum.size(); ++i) {
            sum[i] += diff;
        }
    }

    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray a = NumArray(nums);
    cout << a.sumRange(0, 2) << endl;
    a.update(1, 2);
    cout << a.sumRange(0, 2) << endl;
    return 0;
}
// Runtime: 164 ms, faster than 6.92% of C++ online submissions for Range Sum Query - Mutable.