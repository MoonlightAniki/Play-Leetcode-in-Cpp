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
        return ((c1 == '1' && c2 >= '0' && c2 <= '9') || (c1 == '2' && c2 >= '0' && c2 <= '6')) ? 1 : 0;
    }

    int numDecodings(const string &s, const int &l, const int &r) {
        if (l - 1 == r) {
            return 1;
        }
        if (l == r) {
            return check(s[l]);
        }
        if (memo[l] != -1) {
            return memo[l];
        }
        memo[l] = check(s[l]) * numDecodings(s, l + 1, r) + check(s[l], s[l + 1]) * numDecodings(s, l + 2, r);
        return memo[l];
    }

public:
    int numDecodings(string s) {
        memo = vector<int>(s.size(), -1);
        return numDecodings(s, 0, s.size() - 1);
    }
};

int main() {
    cout << Solution().numDecodings("226") << endl;
    cout << Solution().numDecodings("12") << endl;
    cout << Solution().numDecodings("0") << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.