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

// Time Limit Exceeded
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        res.clear();
        visited = vector<bool>(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        vector<int> solution;
        backtrack(candidates, target, 0, solution);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<bool> visited;

    void backtrack(vector<int> &candidates, int target, int index, vector<int> &solution) {
        if (target == 0) {
            res.push_back(solution);
            return;
        }
        if (index == candidates.size()) {
            return;
        }
        for (int i = index; i < candidates.size(); ++i) {
            if (!visited[i]) {
                if (i > 0 && candidates[i] == candidates[i - 1] && !visited[i - 1]) {
                    continue;
                }
                solution.push_back(candidates[i]);
                visited[i] = true;
                backtrack(candidates, target - candidates[i], i + 1, solution);
                solution.pop_back();
                visited[i] = false;
            }
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