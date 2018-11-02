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
#include <cassert>
#include <ctime>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int l = 0, r = nums.size() - 1;
        srand(time(NULL));
        return partition(nums, l, r, nums.size() - k);
    }

private:
    int partition(vector<int> &nums, int l, int r, int k) {
        if (l == r) {
            assert(l == k);
            return nums[k];
        }
        swap(nums[l], nums[rand() % (r - l + 1) + l]);
        int v = nums[l];
        int p = l;//num[l+1...p]<v, nums[p+1...k)>=v
        for (int k = l + 1; k <= r; ++k) {
            if (nums[k] < v) {
                swap(nums[++p], nums[k]);
            }
        }
        swap(nums[l], nums[p]);
        if (p == k) {
            return nums[p];
        } else if (p < k) {
            return partition(nums, p + 1, r, k);
        } else {
            return partition(nums, l, p - 1, k);
        }
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << Solution().findKthLargest(nums, 2) << endl;

    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << Solution().findKthLargest(nums, 4) << endl;

    return 0;
}
// Runtime: 12 ms, faster than 49.56% of C++ online submissions for Kth Largest Element in an Array.