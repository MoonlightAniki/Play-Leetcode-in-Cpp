// 387. First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/
/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[256] = {0};
        for (const char &c : s) {
            ++freq[c];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 24 ms, faster than 98.29% of C++ online submissions for First Unique Character in a String.