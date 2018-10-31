// 347. Top K Frequency Elements
// https://leetcode.com/problems/top-k-frequent-elements/
/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> freq;
        vector<vector<int>> bucket(nums.size() + 1);
        for (const int &num : nums) {
            ++freq[num];
        }
        for (const pair<int, int> &p : freq) {
            int n = p.second;
            int num = p.first;
            bucket[n].push_back(num);
        }
        vector<int> res;
        for (int i = nums.size(); i > 0 && res.size() < k; --i) {
            res.insert(res.end(), bucket[i].begin(), bucket[i].end());
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> res = Solution().topKFrequent(nums, 2);
    for (const int &num : res) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}
// Runtime: 16 ms, faster than 62.92% of C++ online submissions for Top K Frequent Elements.