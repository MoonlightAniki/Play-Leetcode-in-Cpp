// 216. Combination Sum III
// https://leetcode.com/problems/combination-sum-iii/
/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:
All numbers will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;

    void findCombination(int index, int sum, vector<int> &solution, int k) {
        if (solution.size() == k) {
            if (sum == 0) {
                res.push_back(solution);
            }
            return;
        }
        for (int i = index; i <= 9; ++i) {
            solution.push_back(i);
            findCombination(i + 1, sum - i, solution, k);
            solution.pop_back();
        }
    }


public:
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        vector<int> solution;
        findCombination(1, n, solution, k);
        return res;
    }
};

int main() {
//    vector<vector<int>> res = Solution().combinationSum3(3, 7);
    vector<vector<int>> res = Solution().combinationSum3(3, 9);
    for (auto a : res) {
        for (auto i : a) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum III.