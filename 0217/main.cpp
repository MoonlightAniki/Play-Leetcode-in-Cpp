// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/
/*
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:
Input: [1,2,3,1]
Output: true

Example 2:
Input: [1,2,3,4]
Output: false

Example 3:
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> record;
        for (const int &num : nums) {
            if (record.find(num) != record.end()) {
                return true;
            }
            record.insert(num);
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << Solution().containsDuplicate(nums) << endl;
    return 0;
}
// Runtime: 20 ms, faster than 98.06% of C++ online submissions for Contains Duplicate.