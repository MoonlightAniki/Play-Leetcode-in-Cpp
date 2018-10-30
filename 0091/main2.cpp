// 91. Decode Ways
// https://leetcode.com/problems/decode-ways/
/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:
Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> memo;

    int check(const char &c) {
        return c >= '1' && c <= '9' ? 1 : 0;
    }

    int check(const char &c1, const char &c2) {
        return (c1 == '1' || (c1 == '2' && c2 >= '0' && c2 <= '6')) ? 1 : 0;
    }

public:
    int numDecodings(string s) {
        if (s.size() == 0) {
            return 0;
        }
        if (s.size() == 1) {
            return check(s[0]);
        }
        vector<int> memo(s.size(), 0);//memo[index]表示s[0...index]范围字符串的编码数
        memo[0] = check(s[0]);
        memo[1] = check(s[0]) * check(s[1]) + check(s[0], s[1]);
        for (int i = 2; i < s.size(); ++i) {
            memo[i] = check(s[i]) * memo[i - 1] + check(s[i - 1], s[i]) * memo[i - 2];
        }
        return memo[s.size() - 1];
    }
};

int main() {
    cout << Solution().numDecodings("226") << endl;
    cout << Solution().numDecodings("12") << endl;
    cout << Solution().numDecodings("0") << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.