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
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector <string> words;
        int start = 0;
        for (int i = start + 1; i <= s.size();) {
            if (i == s.size() || s[i] == ' ') {
                words.push_back(s.substr(start, i - start));
                reverse(words.back().begin(), words.back().end());
                start = i + 1;
                i = start + 1;
            } else {
                ++i;
            }
        }
        if (words.size() == 0) {
            return "";
        }
        string res = words[0];
        for (int i = 1; i < words.size(); ++i) {
            res += ' ' + words[i];
        }
        return res;
    }
};

int main() {
    cout << Solution().reverseWords("Let's take LeetCode contest") << endl;
    return 0;
}
// Runtime: 20 ms, faster than 47.62% of C++ online submissions for Reverse Words in a String III.