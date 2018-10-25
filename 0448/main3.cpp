// 448. Find All Numbers Disappeared in a Array
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        nums.insert(nums.begin(), 0);
        for (int i = 1; i < nums.size(); ++i) {
            int appear = abs(nums[i]);
            if (nums[appear] > 0) {
                nums[appear] = -nums[appear];
            }
        }
        vector<int> res;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> res = Solution().findDisappearedNumbers(nums);
    for (const int &num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
// Runtime: 108 ms, faster than 49.00% of C++ online submissions for Find All Numbers Disappeared in an Array.