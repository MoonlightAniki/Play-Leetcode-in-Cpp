// 66. Plus One
// https://leetcode.com/problems/plus-one/
/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                ++digits[i];
                return digits;
            }
        }
        vector<int> res(digits.size() + 1, 0);
        res[0] = 1;
        return res;
    }
};

int main() {
//    vector<int> digits = {4, 3, 2, 1};
//    vector<int> digits = {9, 3, 9, 9};
    vector<int> digits = {9, 9, 9, 9};
    vector<int> res = Solution().plusOne(digits);
    for (const int &i : res) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Plus One.