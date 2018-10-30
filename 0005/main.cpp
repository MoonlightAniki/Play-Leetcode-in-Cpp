// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/
/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.size(); ++i) {
            string p1 = findPalindrome(s, i, i);
            string p2 = findPalindrome(s, i, i + 1);
            res = max(res, p1, p2);
        }
        return res;
    }

private:
    string max(const string &a, const string &b, const string &c) {
        return a.size() > b.size() ? (a.size() > c.size() ? a : c) : (b.size() > c.size() ? b : c);
    }

    string findPalindrome(const string &s, int aIndex, int bIndex) {
        if (bIndex >= s.size() || s[aIndex] != s[bIndex]) {
            return "";
        }
        int left = aIndex;
        int right = bIndex;
        while (left - 1 >= 0 && right + 1 < s.size() && s[left - 1] == s[right + 1]) {
            --left;
            ++right;
        }
        return s.substr(left, right - left + 1);
    }
};

int main() {
    cout << Solution().longestPalindrome("cbbd") << endl;
    cout << Solution().longestPalindrome("ababd") << endl;
    return 0;
}
// Runtime: 20 ms, faster than 56.35% of C++ online submissions for Longest Palindromic Substring.