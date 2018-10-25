// 917. Reverse Only Letters
// https://leetcode.com/problems/reverse-only-letters/
/*
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

Example 1:
Input: "ab-cd"
Output: "dc-ba"

Example 2:
Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Example 3:
Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"


Note:
    S.length <= 100
    33 <= S[i].ASCIIcode <= 122
    S doesn't contain \ or "
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {

        int start = 0;
        int end = S.size() - 1;
        while (true) {
            while (start < S.size() && !isalpha(S[start])) {
                ++start;
            }
            while (end >= 0 && !isalpha(S[end])) {
                --end;
            }
            if (start > end) {
                break;
            }
            swap(S[start], S[end]);
            ++start;
            --end;
        }

        return S;
    }
};

int main() {
    cout << Solution().reverseOnlyLetters("a-bC-dEf-ghIj") << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Only Letters.