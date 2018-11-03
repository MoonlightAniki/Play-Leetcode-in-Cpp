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
            res = max(res, calArea(height, l, r));

            int nextHigherIndex = next_higher_index(height, l, r);
            int preHigherIndex = pre_higher_index(height, l, r);
            if (calArea(height, nextHigherIndex, r) >= calArea(height, l, preHigherIndex)) {
                l = nextHigherIndex;
            } else {
                r = preHigherIndex;
            }
        }
        return res;
    }

private:
    int next_higher_index(vector<int> &nums, int index, int r) {
        for (int i = index + 1; i < r; ++i) {
            if (nums[i] > nums[index]) {
                return i;
            }
        }
        return r;
    }

    int pre_higher_index(vector<int> &nums, int l, int index) {
        for (int i = index - 1; i > l; --i) {
            if (nums[i] > nums[index]) {
                return i;
            }
        }
        return l;
    }

    int calArea(vector<int> &height, int l, int r) {
        return (r - l) * min(height[l], height[r]);
    }
};

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << Solution().maxArea(height) << endl;
    return 0;
}
// Runtime: 156 ms, faster than 27.73% of C++ online submissions for Container With Most Water.