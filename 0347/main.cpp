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
#include <queue>

using namespace std;

// 使用优先队列，c++中的优先队列默认是最大堆
class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> freq;
        for (const int &num : nums) {
            ++freq[num];
        }
        priority_queue<pair<int, int>> pq;//first表示出现的次数，second表示nums中的元素
        vector<int> res;
        for (const pair<int, int> &p : freq) {
            pq.push(make_pair(p.second, p.first));
            if (pq.size() > freq.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
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
// Runtime: 12 ms, faster than 98.90% of C++ online submissions for Top K Frequent Elements.