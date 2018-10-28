// 1. Two Sum
// https://leetcode.com/problems/two-sum/
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); ++i) {
            if (record.find(target - nums[i]) == record.end()) {
                record[nums[i]] = i;
            } else {
                return {record[target - nums[i]], i};
            }
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    vector<int> res = Solution().twoSum(nums, 18);
    for (auto a : res) {
        cout << a << ' ';
    }
    cout << endl;
    return 0;
}
// Runtime: 8 ms, faster than 70.14% of C++ online submissions for Two Sum.