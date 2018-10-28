// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/
/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
    The number of elements initialized in nums1 and nums2 are m and n respectively.
    You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
Output: [1,2,2,3,5,6]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> aux(m + n);
        int i = 0;
        int j = 0;
        for (int k = 0; k < m + n; ++k) {
            if (i >= m) {
                aux[k] = nums2[j++];
            } else if (j >= n) {
                aux[k] = nums1[i++];
            } else if (nums1[i] <= nums2[j]) {
                aux[k] = nums1[i++];
            } else {
                aux[k] = nums2[j++];
            }
        }
        nums1 = aux;
    }
};
// Runtime: 4 ms, faster than 99.52% of C++ online submissions for Merge Sorted Array.