// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/
/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:
All given inputs are in lowercase letters a-z.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }
        string res = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i].find(res) != 0) {
                res = res.substr(0, res.size() - 1);
                i = 0;
            }
        }
        return res;
    }
};

int main() {
    vector<string> strs = {"flow", "flower", "flight"};
    cout << Solution().longestCommonPrefix(strs) << endl;
    return 0;
}
// Runtime: 4 ms, faster than 98.74% of C++ online submissions for Longest Common Prefix.