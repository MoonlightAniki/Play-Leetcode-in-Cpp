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

class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r) {
            res = max(res, (r - l) * min(height[l], height[r]));

            // 增加面积的方法 将较低的边增大
            if (height[l] < height[r]) {
                int next;
                for (next = l + 1; next < r && height[next] <= height[l]; ++next);
                l = next;
            } else {
                int prev;
                for (prev = r - 1; prev > l && height[prev] <= height[r]; --prev);
                r = prev;
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
// Runtime: 12 ms, faster than 98.47% of C++ online submissions for Container With Most Water.