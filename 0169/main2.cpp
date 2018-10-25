// 169. Majority Element
// https://leetcode.com/problems/majority-element/
/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (++freq[nums[i]] > n / 2) {
                return nums[i];
            }
        }
        return -1;
    }
};

int main() {
    vector<int> vec{3, 2, 3};
    cout << Solution().majorityElement(vec) << endl;
    return 0;
}
// Runtime: 12 ms, faster than 97.87% of C++ online submissions for Majority Element.