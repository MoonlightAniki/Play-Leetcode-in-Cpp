// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/
/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, path, res);
        return res;
    }

private:
    void backtrack(vector<int> &nums, int target, int index, vector<int> &path, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (target < 0 || index == nums.size()) {
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            backtrack(nums, target - nums[i], i + 1, path, res);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> res = Solution().combinationSum2(candidates, 8);
    for (auto v : res) {
        for (auto a : v) {
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
}
// Runtime: 8 ms, faster than 70.16% of C++ online submissions for Combination Sum II.