// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/
/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:
Input: "race a car"
Output: false
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (true) {
            while (i < j && !isalnum(s[i])) {
                ++i;
            }
            while (i < j && !isalnum(s[j])) {
                --j;
            }
            if (i >= j) {
                break;
            }
            if (toupper(s[i]) != toupper(s[j])) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};

int main() {
    cout << Solution().isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << Solution().isPalindrome("race a car") << endl;
    return 0;
}
// Runtime: 8 ms, faster than 61.13% of C++ online submissions for Valid Palindrome.