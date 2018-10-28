// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/
/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21

Note:
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
    For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int temp = abs(x);
        int res = 0;
        int m;
        while (temp) {
            m = res * 10 + temp % 10;
            if ((m - temp % 10) / 10 != res) {
                return 0;
            }
            res = m;
            temp /= 10;
        }
        return x < 0 ? -res : res;
    }
};

int main() {
    cout << Solution().reverse(0x7fffffff) << endl;
    cout << Solution().reverse(123) << endl;
    cout << Solution().reverse(-123) << endl;
    cout << Solution().reverse(120) << endl;
    cout << Solution().reverse(1534236469) << endl;
    return 0;
}
// Runtime: 12 ms, faster than 97.71% of C++ online submissions for Reverse Integer.