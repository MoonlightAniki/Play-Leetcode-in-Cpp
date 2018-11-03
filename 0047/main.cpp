// 47. Permutations II
// https://leetcode.com/problems/permutations-ii/
/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        res.clear();
        used = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        vector<int> path;
        backtrack(nums, path);
        return res;
    }

private:
    vector<bool> used;
    vector<vector<int>> res;

    void backtrack(vector<int> &nums, vector<int> &path) {
        if (nums.size() == path.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                    continue;
                }
                path.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, path);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> res = Solution().permuteUnique(nums);
    for (auto v : res) {
        for (auto a : v) {
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
}
// Runtime: 16 ms, faster than 99.41% of C++ online submissions for Permutations II.