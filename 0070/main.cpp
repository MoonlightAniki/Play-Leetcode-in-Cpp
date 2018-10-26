// Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/
/*
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> memo;

    int __climbStairs(int n) {
        if (memo[n] != -1) {
            return memo[n];
        }
        if (n == 0 || n == 1) {
            memo[n] = 1;
            return 1;
        }
        memo[n] = __climbStairs(n - 1) + __climbStairs(n - 2);
        return memo[n];
    }

public:
    int climbStairs(int n) {
        memo = vector<int>(n + 1, -1);
        __climbStairs(n);
        return memo[n];
    }
};

int main() {
    cout << Solution().climbStairs(3) << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.