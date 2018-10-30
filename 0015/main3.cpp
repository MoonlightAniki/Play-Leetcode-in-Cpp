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
        sort(nums.begin(), nums.end());
        for (int index = 0; index < nums.size();) {
            int bindex = index + 1;
            int cindex = nums.size() - 1;
            while (bindex < cindex) {
                if (nums[bindex] + nums[cindex] == -nums[index]) {
                    res.push_back({nums[index], nums[bindex], nums[cindex]});
                    bindex = next_num_index(nums, bindex);
                    cindex = pre_num_index(nums, cindex);
                } else if (nums[bindex] + nums[cindex] < -nums[index]) {
                    bindex = next_num_index(nums, bindex);
                } else {
                    cindex = pre_num_index(nums, cindex);
                }
            }
            index = next_num_index(nums, index);
        }
        return res;
    }

private:
    int next_num_index(vector<int> &nums, int index) {
        for (int i = index + 1; i < nums.size(); ++i) {
            if (nums[i] != nums[index]) {
                return i;
            }
        }
        return nums.size();
    }

    int pre_num_index(vector<int> &nums, int index) {
        for (int i = index - 1; i >= 0; --i) {
            if (nums[i] != nums[index]) {
                return i;
            }
        }
        return -1;
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
// Runtime: 88 ms, faster than 65.94% of C++ online submissions for 3Sum.