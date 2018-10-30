// 15. 3Sum
// https://leetcode.com/problems/3sum/
/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets
in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                for (int j = i + 1, k = n - 1; j < k;) {
                    if (nums[j] + nums[k] == -nums[i]) {
                        res.push_back({nums[i], nums[j], nums[k]});
                        while (j + 1 < k && nums[j + 1] == nums[j]) {
                            ++j;
                        }
                        while (k - 1 > j && nums[k - 1] == nums[k]) {
                            --k;
                        }
                        ++j;
                        --k;
                    } else if (nums[j] + nums[k] < -nums[i]) {
                        ++j;
                    } else {
                        --k;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4, -1};
    vector<vector<int>> res = Solution().threeSum(nums);
    for (const vector<int> &v : res) {
        for (const int &i : v) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
// Runtime: 76 ms, faster than 82.09% of C++ online submissions for 3Sum.