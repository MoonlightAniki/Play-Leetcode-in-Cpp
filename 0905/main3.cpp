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
#include <algorithm>

using namespace std;

/// Sorting by custom comparator
/// Time Complexity : O(nlogn)
/// Space Complexity: O(1)
class Solution {
private:
    static bool cmp(const int &a, const int &b) {
        if (a % 2 != b % 2) {
            return a % 2 == 0;
        } else {
            return a < b;
        }
    }

public:
    vector<int> sortArrayByParity(vector<int> &A) {
        sort(A.begin(), A.end(), cmp);//使用sort函数需要引入algorithm
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
// Runtime: 44 ms, faster than 26.08% of C++ online submissions for Sort Array By Parity.