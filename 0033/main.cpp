// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/
/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [6,7,0,1,2,4,5], target = 3
Output: -1
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        // 找到最小值的索引,也就是旋转点的索引
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        int rotate = lo;
        lo = 0;
        hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int realMid = (mid + rotate) % (nums.size());
            if (target == nums[realMid]) {
                return realMid;
            } else if (target < nums[realMid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }

};

int main() {
    vector<int> nums = {5, 1, 2, 3, 4};
    cout << Solution().search(nums, 1) << endl;

    nums = {1, 3};
    cout << Solution().search(nums, 1) << endl;

    nums = {3, 1};
    cout << Solution().search(nums, 1) << endl;
    return 0;
}
// Runtime: 4 ms, faster than 99.39% of C++ online submissions for Search in Rotated Sorted Array.