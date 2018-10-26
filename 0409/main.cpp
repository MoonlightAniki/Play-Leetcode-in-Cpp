// 409. Longest Palindrome
// https://leetcode.com/problems/longest-palindrome/
/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:
Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int freq[256] = {0};
        for (const char &c : s) {
            ++freq[c];
        }
        int oddCount = 0;
        for (const int &count : freq) {
            if (count % 2) {
                ++oddCount;
            }
        }
        if (oddCount == 0) {
            return s.size();
        } else {
            return s.size() - oddCount + 1;
        }
    }
};

int main() {
    string s = "abccccdd";
    cout << Solution().longestPalindrome(s) << endl;
    return 0;
}
// Runtime: 4 ms, faster than 92.79% of C++ online submissions for Longest Palindrome.