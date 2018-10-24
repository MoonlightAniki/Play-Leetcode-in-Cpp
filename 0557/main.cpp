// 557. Reverse Words in a String III
// https://leetcode.com/problems/reverse-words-in-a-string-iii/
/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res;
        string tmp;
        for (const char &c : s) {
            if (c == ' ') {
                res += reverse(tmp);
                res += c;
                tmp = "";
            } else {
                tmp += c;
            }
        }
        res += reverse(tmp);
        return res;
    }

private:
    string reverse(string &s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            swap(s[i], s[s.size() - 1 - i]);
        }
        return s;
    }
};

int main() {
    cout << Solution().reverseWords("Let's take LeetCode contest") << endl;
    return 0;
}
// Runtime: 16 ms, faster than 96.78% of C++ online submissions for Reverse Words in a String III.