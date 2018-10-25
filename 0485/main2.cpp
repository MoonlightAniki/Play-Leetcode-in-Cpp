// 485. Maximum Consecutive Ones
// https://leetcode.com/problems/max-consecutive-ones/
/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.

Note:
    The input array will only contain 0 and 1.
    The length of input array is a positive integer and will not exceed 10,000
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int res = 0;
        int count = 0;
        for (const int &num : nums) {
            if (num == 1) {
                ++count;
            } else {
                count = 0;
            }

            res = max(res, count);
        }
        return res;
    }
};

int main() {
    vector<int> nums{1, 1, 0, 1, 1, 1, 0, 1, 1};
//    vector<int> nums{1};
    cout << Solution().findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
// Runtime: 28 ms, faster than 54.25% of C++ online submissions for Max Consecutive Ones.