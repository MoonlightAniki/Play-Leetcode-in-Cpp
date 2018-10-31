// 46. Permutations
// https://leetcode.com/problems/permutations/
/*
Given a collection of distinct integers, return all possible permutations.

Example:
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        visited = vector<bool>(nums.size(), false);
        res.clear();
        vector<int> s;
        generatePermutation(nums, s);
        return res;
    }

private:
    vector<bool> visited;
    vector<vector<int>> res;

    void generatePermutation(vector<int> &nums, vector<int> &solution) {
        if (solution.size() == nums.size()) {
            res.push_back(solution);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i]) {
                solution.push_back(nums[i]);
                visited[i] = true;
                generatePermutation(nums, solution);
                solution.pop_back();
                visited[i] = false;
            }
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = Solution().permute(nums);
    for (auto &a : res) {
        for (auto &b : a) {
            cout << b << ' ';
        }
        cout << endl;
    }
    return 0;
}
// Runtime: 8 ms, faster than 99.61% of C++ online submissions for Permutations.