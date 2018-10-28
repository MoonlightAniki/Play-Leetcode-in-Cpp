// 680. Valid Palindrome II
// https://leetcode.com/problems/valid-palindrome-ii/
/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True

Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size() <= 1) {
            return true;
        }
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return isPalindrome(s.substr(i, j - i)) || isPalindrome(s.substr(i + 1, j - i));
            }
        }
        return true;
    }

private:
    bool isPalindrome(const string &s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    cout << Solution().validPalindrome("abca") << endl;
    cout << Solution().validPalindrome("aba") << endl;
    return 0;
}
// Runtime: 76 ms, faster than 98.26% of C++ online submissions for Valid Palindrome II.