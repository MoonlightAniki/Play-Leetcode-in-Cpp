// 647. Palindromic Strings
// https://leetcode.com/problems/palindromic-substrings/
/*
Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Note:
The input string length won't exceed 1000.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        res = 0;
        for (int i = 0; i < s.size(); ++i) {
            findPalindrome(s, i, i);
            findPalindrome(s, i, i + 1);
        }
        return res;
    }

private:
    int res;

    void findPalindrome(const string &s, int index1, int index2) {
        for (int i = index1, j = index2; i >= 0 && j < s.size() && s[i] == s[j]; --i, ++j) {
            ++res;
        }
    }
};

int main() {
    cout << Solution().countSubstrings("aaa") << endl;
    cout << Solution().countSubstrings("a") << endl;
    cout << Solution().countSubstrings("") << endl;
    cout << Solution().countSubstrings("aba") << endl;
    return 0;
}
// Runtime: 4 ms, faster than 94.51% of C++ online submissions for Palindromic Substrings.