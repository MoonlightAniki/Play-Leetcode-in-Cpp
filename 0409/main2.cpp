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
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int odds = 0;
        for (char c = 'A'; c <= 'z'; ++c) {
            odds += count(s.begin(), s.end(), c) & 1;
        }
        if (odds == 0) {
            return s.size();
        } else {
            return s.size() - odds + 1;
        }
    }
};

int main() {
    string s = "abccccdd";
    cout << Solution().longestPalindrome(s) << endl;
    return 0;
}
// Runtime: 8 ms, faster than 16.83% of C++ online submissions for Longest Palindrome.