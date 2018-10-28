// 581. Shortest Unsorted Continuous Subarray
// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:
    Then length of the input array is in range [1, 10,000].
    The input array may contain duplicates, so ascending order here means <=.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int l = 0;//nums[0...l]左侧最长的上升子序列
        int r = nums.size() - 1;//nums[r...nums.size()-1]右侧最长的上升子序列
        // 中间部分nums[l+1...r-1]


        while (l + 1 < nums.size() && nums[l] <= nums[l + 1]) {
            ++l;
        }
        if (l >= r) {
            return 0;
        }
        while (r - 1 >= 0 && nums[r - 1] <= nums[r]) {
            --r;
        }

        // 查找nums[l+1...r-1]范围内的最小值和最大值
        int _min = 0x7fffffff;
        int _max = 0x80000000;
        for (int k = l; k <= r; ++k) {
            _min = min(_min, nums[k]);
            _max = max(_max, nums[k]);
        }
        while (l >= 0 && nums[l] > _min) {
            --l;
        }
        while (r < nums.size() && nums[r] < _max) {
            ++r;
        }
        return r - l - 1;
    }
};

int main() {
//    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
//    vector<int> nums = {2, 3, 4, 5, 6, 7, 8};
//    vector<int> nums = {8, 7, 6, 5, 4, 3, 2};
    vector<int> nums = {2, 1};
    cout << Solution().findUnsortedSubarray(nums) << endl;
    return 0;
}
// Runtime: 24 ms, faster than 98.34% of C++ online submissions for Shortest Unsorted Continuous Subarray.