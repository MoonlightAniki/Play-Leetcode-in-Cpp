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
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> record;
        for (const char &c : s) {
            ++record[c];
        }
        for (const char &c : t) {
            --record[c];
        }
        for (unordered_map<char, int>::iterator it = record.begin(); it != record.end(); ++it) {
            if (it->second) {
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
// Runtime: 16 ms, faster than 39.83% of C++ online submissions for Valid Anagram.