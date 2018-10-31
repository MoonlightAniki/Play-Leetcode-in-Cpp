// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/
/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements that appear twice in this array.
Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> res;
        int n = nums.size();
        if (n == 0 || n == 1) {
            return res;
        }
        for (int i = 0; i < n; ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                res.push_back(index + 1);
            } else {
                nums[index] *= -1;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> res = Solution().findDuplicates(nums);
    for (const int &num : res) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}
// Runtime: 116 ms, faster than 46.98% of C++ online submissions for Find All Duplicates in an Array.