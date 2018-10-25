// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/
/*
Given two arrays, write a function to compute their intersection.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]


Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]


Note:
    1. Each element in the result must be unique.
    2. The result can be in any order.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> record(nums1.begin(), nums1.end());
        unordered_set<int> res;
        for (const int &num : nums2) {
            if (record.find(num) != record.end()) {
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Intersection of Two Arrays.