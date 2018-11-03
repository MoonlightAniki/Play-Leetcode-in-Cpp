// 90. Subsets II
// https://leetcode.com/problems/subsets-ii/
/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        res.clear();
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); ++i) {
            vector<int> solution;
            visited = vector<bool>(nums.size(), false);
            backtrack(nums, i, 0, solution);
        }
        return res;
    }

private:
    vector<vector<int>> res;
    vector<bool> visited;

    void backtrack(vector<int> &nums, int k, int index, vector<int> &solution) {
        if (solution.size() == k) {
            res.push_back(solution);
            return;
        }
        if (index == nums.size()) {
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            if (!visited[i]) {
                if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                    continue;
                }
                solution.push_back(nums[i]);
                visited[i] = true;
                backtrack(nums, k, i + 1, solution);
                solution.pop_back();
                visited[i] = false;
            }
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> res = Solution().subsetsWithDup(nums);
    for (auto v : res) {
        for (auto a : v) {
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
}
// Runtime: 12 ms, faster than 20.85% of C++ online submissions for Subsets II.