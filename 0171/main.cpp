// 171. Excel Sheet Column Number
// https://leetcode.com/problems/excel-sheet-column-number/
/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...


Example 1:
Input: "A"
Output: 1

Example 2:
Input: "AB"
Output: 28

Example 3:
Input: "ZY"
Output: 701
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (const char &c : s) {
            res = 26 * res + (c - 'A' + 1);
        }
        return res;
    }
};

int main() {
    cout << Solution().titleToNumber("AB") << endl;
    cout << Solution().titleToNumber("ZY") << endl;
    return 0;
}
// Runtime: 4 ms, faster than 98.81% of C++ online submissions for Excel Sheet Column Number.