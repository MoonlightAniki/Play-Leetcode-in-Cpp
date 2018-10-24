// 905. Sort Array By Pairty
// https://leetcode.com/problems/sort-array-by-parity/
/*
 Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
You may return any answer array that satisfies this condition.

Example 1:
Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Note:
    1. 1 <= A.length <= 5000
    2. 0 <= A[i] <= 5000
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        int even = 0;
        int odd = A.size() - 1;
        while (true) {
            while (even < A.size() && A[even] % 2 == 0) {
                ++even;
            }
            while (odd >= 0 && A[odd] % 2 == 1) {
                --odd;
            }
            if (even > odd) {
                break;
            }
            swap(A[even], A[odd]);
            ++even;
            --odd;
        }
        return A;
    }
};

int main() {
    vector<int> A = {3, 1, 2, 4};
    vector<int> res = Solution().sortArrayByParity(A);
    for (const int &i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
// Runtime: 24 ms, faster than 97.88% of C++ online submissions for Sort Array By Parity.