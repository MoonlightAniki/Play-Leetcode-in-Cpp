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
        int start = 0;
        for (int i = start + 1; i <= s.size();) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i + 1;
                i = start + 1;
            } else {
                ++i;
            }
        }
        return s;
    }

private:
    void reverse(string &s, const int &start, const int &end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
    }
};

int main() {
    cout << Solution().reverseWords("Let's take LeetCode contest") << endl;
    return 0;
}
// Runtime: 16 ms, faster than 96.78% of C++ online submissions for Reverse Words in a String III.