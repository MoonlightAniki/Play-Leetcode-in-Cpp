// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
    1. Open brackets must be closed by the same type of brackets.
    2. Open brackets must be closed in the correct order.
    3. Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2) {
            return false;
        }
        stack<char> res;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                res.push(s[i]);
            } else {
                if (res.empty()) {
                    return false;
                }
                char c = res.top();
                res.pop();
                if (s[i] == ')' && c != '(') {
                    return false;
                }
                if (s[i] == ']' && c != '[') {
                    return false;
                }
                if (s[i] == '}' && c != '{') {
                    return false;
                }
            }
        }
        return res.empty();
    }
};

int main() {
    cout << Solution().isValid("()[]{}") << endl;
    cout << Solution().isValid("([)]") << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.