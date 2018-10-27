// 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/
/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Input: "hello"
Output: "holle"

Example 2:
Input: "leetcode"
Output: "leotcede"

Note:
The vowels does not include the letter "y".
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (true) {
            while (i < s.size() && !isVowel(s[i])) {
                ++i;
            }
            while (j >= 0 && !isVowel(s[j])) {
                --j;
            }
            if (i > j) {
                break;
            }
            swap(s[i++], s[j--]);
        }
        return s;
    };
private:
    bool isVowel(const char &c) {
        return c == 'a' || c == 'A' ||
               c == 'e' || c == 'E' ||
               c == 'i' || c == 'I' ||
               c == 'o' || c == 'O' ||
               c == 'u' || c == 'U';
    }
};

int main() {
    cout << Solution().reverseVowels("leetcode") << endl;
    return 0;
}
// Runtime: 8 ms, faster than 98.33% of C++ online submissions for Reverse Vowels of a String.