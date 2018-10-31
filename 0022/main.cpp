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
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        for (int i = 1; i <= n; ++i) {//一共i对括号
            // 其中j对括号在新增的一对括号内部，i-j-1对括号在外部
            // f(i) = '(' + f(j) + ')' + f(i-j-1)
            for (int j = 0; j < i; ++j) {
                vector<string> in = dp[j];
                vector<string> out = dp[i - j - 1];
                for (int m = 0; m < in.size(); ++m) {
                    for (int n = 0; n < out.size(); ++n) {
                        dp[i].push_back('(' + in[m] + ")" + out[n]);
                    }
                }
            }
        }
        return dp[n];
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