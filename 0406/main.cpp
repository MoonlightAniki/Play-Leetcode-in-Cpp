// 406. Queue Reconstruction By Height
// https://leetcode.com/problems/queue-reconstruction-by-height/
// Time: 2018-11-07
/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
        sort(people.begin(), people.end(), [](pair<int, int> &a, pair<int, int> &b) {
            // 按高度从大到小排列，如果高度相同，k较小的排前面
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        });
        vector<pair<int, int>> res;
        for (const pair<int, int> &p : people) {
            res.insert(res.begin() + p.second, p);
        }
        return res;
    }
};

int main() {
    vector<pair<int, int>> people = {
            {7, 0},
            {4, 4},
            {7, 1},
            {5, 0},
            {6, 1},
            {5, 2},
    };
    vector<pair<int, int>> res = Solution().reconstructQueue(people);
    for (auto p : res) {
        cout << p.first << ", " << p.second << endl;
    }
    return 0;
}