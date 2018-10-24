// 922. Sort Array By Parity II
// https://leetcode.com/problems/sort-array-by-parity-ii/
/*
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.
Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
You may return any answer array that satisfies this condition.

Example 1:
Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

Note:
    1. 2 <= A.length <= 20000
    2. A.length % 2 == 0
    3. 0 <= A[i] <= 1000
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &A) {
        int odd = 0;
        int even = 0;
        for (int i = 0; i < A.size(); ++i) {
            // i是偶数
            if (i % 2 == 0) {
                while (A[even] % 2 == 1) {
                    ++even;
                }
                swap(A[i], A[even]);
                ++even;
            } else {
                while (A[odd] % 2 == 0) {
                    ++odd;
                }
                swap(A[i], A[odd]);
                ++odd;
            }
        }
        return A;
    }
};

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    vector<int> vec = {4, 1, 1, 0, 1, 0};
    Solution().sortArrayByParityII(vec);
    for (const int &i : vec) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
//Runtime: 120 ms, faster than 25.72% of C++ online submissions for Sort Array By Parity II.