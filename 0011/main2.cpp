// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/
/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
 */

#include <iostream>
#include <vector>

using namespace std;

/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            for (int j = i + 1; j < height.size(); ++j) {
                res = max(res, (j - i) * min(height[i], height[j]));
            }
        }
        return res;
    }
};

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << Solution().maxArea(height) << endl;
    return 0;
}
// Runtime: 1312 ms, faster than 4.01% of C++ online submissions for Container With Most Water.