// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/
/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */

#include <iostream>

using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[256] = {0};
        for (const char &c : s) {
            ++freq[c];
        }
        for (const char &c : t) {
            --freq[c];
        }
        for (const int &i : freq) {
            if (i) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    cout << Solution().isAnagram("anagram", "nagaram") << endl;
    cout << Solution().isAnagram("rat", "car") << endl;
    return 0;
}
// Runtime: 8 ms, faster than 82.51% of C++ online submissions for Valid Anagram.