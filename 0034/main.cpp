// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int index = binarySearch(nums, 0, nums.size() - 1, target);
        if (index == -1) {
            return {-1, -1};
        }
        int start = find_start_index(nums, index);
        int end = find_end_index(nums, index);
        return {start, end};
    }

private:
    int binarySearch(const vector<int> &nums, int l, int r, int target) {
        if (l > r) {
            return -1;
        }
        int mid = l + (r - l) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target < nums[mid]) {
            return binarySearch(nums, l, mid - 1, target);
        } else {
            return binarySearch(nums, mid + 1, r, target);
        }
    }

    int find_start_index(const vector<int> &nums, int index) {
        int i = index - 1;
        for (; i >= 0 && nums[i] == nums[index]; --i);
        return i + 1;
    }

    int find_end_index(const vector<int> &nums, int index) {
        int i = index + 1;
        for (; i < nums.size() && nums[i] == nums[index]; ++i);
        return i - 1;
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
//    vector<int> res = Solution().searchRange(nums, 6);
    vector<int> res = Solution().searchRange(nums, 8);
    for (auto &a : res) {
        cout << a << ' ';
    }
    cout << endl;
    return 0;
}
// Runtime: 8 ms, faster than 61.91% of C++ online submissions for Find First and Last Position of Element in Sorted Array.