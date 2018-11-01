// 78. Subsets
// https://leetcode.com/problems/subsets/
/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        res.clear();
        for (int i = 0; i <= nums.size(); ++i) {
            vector<int> solution;
            backtrack(nums, 0, solution, i);
        }
        return res;
    }

private:
    vector<vector<int>> res;

    void backtrack(vector<int> &nums, int index, vector<int> &solution, int n) {
        if (solution.size() == n) {
            res.push_back(solution);
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            solution.push_back(nums[i]);
            backtrack(nums, i + 1, solution, n);
            solution.pop_back();
        }
    }
};
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Subsets.