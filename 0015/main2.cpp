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
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) {
            return res;
        }

        unordered_map<int, int> counter;
        for (const int &num : nums) {
            ++counter[num];
        }
        if (counter[0] >= 3) {
            res.push_back({0, 0, 0});
        }

        // remove duplicates
        sort(nums.begin(), nums.end());
        vector<int>::iterator iter = unique(nums.begin(), nums.end());
        nums.erase(iter, nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] * 2 + nums[j] == 0 && counter[nums[i]] >= 2) {
                    res.push_back({nums[i], nums[i], nums[j]});
                }
                if (nums[i] + nums[j] * 2 == 0 && counter[nums[j]] >= 2) {
                    res.push_back({nums[i], nums[j], nums[j]});
                }
                int c = 0 - nums[i] - nums[j];
                if (c > nums[j] && counter[c] > 0) {
                    res.push_back({nums[i], nums[j], c});
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
// Runtime: 224 ms, faster than 15.33% of C++ online submissions for 3Sum.