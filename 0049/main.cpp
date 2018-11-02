// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/
/*
Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
All inputs will be in lowercase.
The order of your output does not matter.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> bucket;
        for (const string &s : strs) {
            bucket[sortString(s)].push_back(s);
        }
        vector<vector<string>> res;
        for (const pair<const string, vector<string>> &p : bucket) {
            res.push_back(p.second);
        }
        return res;
    }

private:
    string sortString(const string &s) {
        vector<char> temp;
        for (const char &c : s) {
            temp.push_back(c);
        }
        sort(temp.begin(), temp.end());
        string res;
        for (const char &c : temp) {
            res.push_back(c);
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 20 ms, faster than 97.20% of C++ online submissions for Group Anagrams.