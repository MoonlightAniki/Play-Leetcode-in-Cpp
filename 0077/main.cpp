// 77. Combinations
// https://leetcode.com/problems/combinations/
/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        vector<int> solution;
        generateCombination(n, k, 1, solution);
        return res;
    }

private:
    vector<vector<int>> res;

    void generateCombination(int n, int k, int index, vector<int> &solution) {
        if (solution.size() == k) {
            res.push_back(solution);
            return;
        }
        for (int i = index; i <= n; ++i) {
            solution.push_back(i);
            generateCombination(n, k, i + 1, solution);
            solution.pop_back();
        }
    }
};

int main() {
    vector<vector<int>> res = Solution().combine(4, 2);
    for (auto v : res) {
        for (auto a : v) {
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
}
// Runtime: 84 ms, faster than 45.61% of C++ online submissions for Combinations.