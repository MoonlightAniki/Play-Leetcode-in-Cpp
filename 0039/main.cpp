// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/
/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        res.clear();
        vector<int> solution;
        backtrack(candidates, 0, target, solution);
        return res;
    }

private:
    vector<vector<int>> res;

    void backtrack(vector<int> &candidates, int index, int target, vector<int> &solution) {
        if (target == 0) {
            res.push_back(solution);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = index; i < candidates.size(); ++i) {
            solution.push_back(candidates[i]);
            backtrack(candidates, i, target - candidates[i], solution);
            solution.pop_back();
        }
    }
};

int main() {
    vector<int> candidates = {2, 3, 5};
    vector<vector<int>> res = Solution().combinationSum(candidates, 8);
    for (auto v : res) {
        for (auto a : v) {
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
}
// Runtime: 8 ms, faster than 99.71% of C++ online submissions for Combination Sum.