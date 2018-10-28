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
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        vector<int> record;
        while (x) {
            record.push_back(x % 10);
            x /= 10;
        }
        for (int i = 0, j = record.size() - 1; i < j; ++i, --j) {
            if (record[i] != record[j]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    cout << Solution().isPalindrome(-1) << endl;
    cout << Solution().isPalindrome(0) << endl;
    cout << Solution().isPalindrome(10) << endl;
    cout << Solution().isPalindrome(101) << endl;
    return 0;
}
// Runtime: 244 ms, faster than 8.46% of C++ online submissions for Palindrome Number.