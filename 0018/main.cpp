// 18. 4Sum
// https://leetcode.com/problems/4sum/
/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that
a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
The solution set must not contain duplicate quadruplets.

Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i = next_num_index(nums, i)) {
            for (int j = i + 1; j < nums.size() - 2; j = next_num_index(nums, j)) {
                // 在 nums[j+1...n-1]范围内查找两个和等于target-nums[i]-nums[j]的元素
                int sum = target - nums[i] - nums[j];
                for (int p = j + 1, q = nums.size() - 1; p < q;) {
                    if (nums[p] + nums[q] == sum) {
                        res.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p = next_num_index(nums, p);
                        q = pre_num_index(nums, q);
                    } else if (nums[p] + nums[q] < sum) {
                        p = next_num_index(nums, p);
                    } else {
                        q = pre_num_index(nums, q);
                    }
                }
            }
        }
        return res;
    }

private:
    int next_num_index(const vector<int> &nums, int index) {
        for (int i = index + 1; i < nums.size(); ++i) {
            if (nums[i] != nums[index]) {
                return i;
            }
        }
        return nums.size();
    }

    int pre_num_index(const vector<int> &nums, int index) {
        for (int i = index - 1; i >= 0; --i) {
            if (nums[i] != nums[index]) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> res = Solution().fourSum(nums, 0);
    for (const vector<int> &vec : res) {
        for (const int &i : vec) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
// Runtime: 28 ms, faster than 54.44% of C++ online submissions for 4Sum.