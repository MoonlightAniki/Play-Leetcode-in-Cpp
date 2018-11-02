// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/
/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Time Complexity : O(nlogk)
// Space Complexity : O(k)
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); ++i) {
            pq.push(nums[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << Solution().findKthLargest(nums, 2) << endl;

    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << Solution().findKthLargest(nums, 4) << endl;

    return 0;
}
// Runtime: 8 ms, faster than 77.31% of C++ online submissions for Kth Largest Element in an Array.