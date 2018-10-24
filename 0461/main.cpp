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
        for (int i = 0; i < 32; ++i) {
            int mask = 1 << i;
            res += ((x & mask) >> i) ^ ((y & mask) >> i);
        }
        return res;
    }
};

int main() {
    cout << Solution().hammingDistance(1, 4) << endl;
    return 0;
}
// Runtime: 4 ms, faster than 51.51% of C++ online submissions for Hamming Distance.