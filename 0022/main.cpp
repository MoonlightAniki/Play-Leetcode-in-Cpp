// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("", 0, 0, res, n);
        return res;
    }

private:
    void backtrack(string s, int open, int close, vector<string> &res, int n) {
        if (s.size() == 2 * n) {
            res.push_back(s);
            return;
        }
        if (open < n) {
            backtrack(s + "(", open + 1, close, res, n);
        }
        if (close < open) {
            backtrack(s + ")", open, close + 1, res, n);
        }
    }
};

int main() {
    vector<string> res = Solution().generateParenthesis(3);
    for (const string &s : res) {
        cout << s << endl;
    }
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Generate Parentheses.