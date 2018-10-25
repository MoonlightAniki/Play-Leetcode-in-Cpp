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
        for (int i = 0; i < nums.size(); ++i) {
            int appear = abs(nums[i]);//出现的数字，取绝对值是因为可能之前该位置被标记了
            if (nums[appear - 1] > 0) {
                nums[appear - 1] = -nums[appear - 1];//将appear-1索引处的元素赋为相反数，表示appear已经出现
            }
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {// 如果i位置未标记，表明i+1未出现
                res.push_back(i + 1);
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
// Runtime: 104 ms, faster than 52.48% of C++ online submissions for Find All Numbers Disappeared in an Array.