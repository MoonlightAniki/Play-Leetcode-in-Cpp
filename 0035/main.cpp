// 35. Search Insert Position
// https://leetcode.com/problems/search-insert-position/
/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

Example 2:
Input: [1,3,5,6], 2
Output: 1

Example 3:
Input: [1,3,5,6], 7
Output: 4

Example 4:
Input: [1,3,5,6], 0
Output: 0
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

private:
    int binarySearch(vector<int> &nums, const int &target, const int &l, const int &r) {
        if (l > r) {
            return l;
        }
        int mid = l + (r - l) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target < nums[mid]) {
            return binarySearch(nums, target, l, mid - 1);
        } else {
            return binarySearch(nums, target, mid + 1, r);
        }
    }
};

int main() {
    vector<int> nums1 = {1, 3, 5, 6};
    cout << Solution().searchInsert(nums1, 5) << endl;

    vector<int> nums2 = {1, 3, 5, 6};
    cout << Solution().searchInsert(nums2, 0) << endl;
    return 0;
}
// Runtime: 4 ms, faster than 98.26% of C++ online submissions for Search Insert Position.