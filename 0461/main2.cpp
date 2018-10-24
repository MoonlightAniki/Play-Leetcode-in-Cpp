// 461. Hamming Distance
// https://leetcode.com/problems/hamming-distance/
/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int n = x ^y;
        while (n) {
//            cout << n << endl;
            ++res;
            n &= n - 1;//n&(n-1)作用：将n的二进制表示中的最低位为1的改为0
        }
        return res;
    }
};

int main() {
    cout << Solution().hammingDistance(1, 4) << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Hamming Distance.