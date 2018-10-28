// 58. Length of Last Word
// https://leetcode.com/problems/length-of-last-word/
/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:
Input: "Hello World"
Output: 5
 */

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream ss(s);
        string word;
        while (ss >> word) {}
        return word.size();
    }
};

int main() {
    cout << Solution().lengthOfLastWord("Hello World ") << endl;
    cout << Solution().lengthOfLastWord("Hello World !") << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Length of Last Word.