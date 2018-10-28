// 205. Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/
/*
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true

Note:
You may assume both s and t have the same length.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash1[256] = {0};
        int hash2[256] = {0};
        for (int i = 0; i < s.size(); ++i) {
            if (hash1[s[i]] != hash2[t[i]]) {
                return false;
            }
            hash1[s[i]] = i + 1;
            hash2[t[i]] = i + 1;
        }
        return true;
    }
};

int main() {
//    cout << Solution().isIsomorphic("egg", "add") << endl;
//    cout << Solution().isIsomorphic("foo", "bar") << endl;
//    cout << Solution().isIsomorphic("paper", "title") << endl;
//    cout << Solution().isIsomorphic("aba", "baa") << endl;
    cout << Solution().isIsomorphic("ab", "aa") << endl;
    return 0;
}
// Runtime: 4 ms, faster than 99.07% of C++ online submissions for Isomorphic Strings.