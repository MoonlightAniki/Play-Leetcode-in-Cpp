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
#include <stack>
#include <unordered_set>

using namespace std;

// Time Limit Exceeded
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<char> chs;
        for (int i = 0; i < n; ++i) {
            chs.push_back('(');
            chs.push_back(')');
        }

        string s;
        visited = vector<bool>(2 * n, false);
        set.clear();
        generateParenthesis(chs, s);
        return vector<string>(set.begin(), set.end());
    }

private:
    vector<bool> visited;
    unordered_set<string> set;


    void generateParenthesis(const vector<char> &chs, string &s) {
        if (s.size() == chs.size()) {
            if (isValidParenthesis(s)) {
                set.insert(s);
            }
            return;
        }

        for (int i = 0; i < chs.size(); ++i) {
            if (!visited[i]) {
                s.push_back(chs[i]);
                visited[i] = true;
                generateParenthesis(chs, s);
                s.pop_back();
                visited[i] = false;
            }
        }
    }


    bool isValidParenthesis(const string &s) {
        stack<char> record;
        for (const char &c : s) {
            if (c == '(') {
                record.push(c);
            } else {
                if (record.empty()) {
                    return false;
                }
                record.pop();
            }
        }
        return record.empty();
    }
};

int main() {
    vector<string> res = Solution().generateParenthesis(5);
    for (const string &s : res) {
        cout << s << endl;
    }
    return 0;
}