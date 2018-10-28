// 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number/
/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:
Input: 121
Output: true

Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Follow up:
Coud you solve it without converting the integer to a string?
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) {
            return true;
        }
        if (x < 0 || x % 10 == 0) {
            return false;
        }
        int sum = 0;
        while (x > sum) {
            sum = 10 * sum + x % 10;
            x /= 10;
        }
        return x == sum || x == sum / 10;
    }
};

int main() {
    cout << Solution().isPalindrome(-1) << endl;
    cout << Solution().isPalindrome(0) << endl;
    cout << Solution().isPalindrome(10) << endl;
    cout << Solution().isPalindrome(101) << endl;
    return 0;
}
// Runtime: 144 ms, faster than 57.80% of C++ online submissions for Palindrome Number.