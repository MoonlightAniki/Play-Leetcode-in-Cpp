// 139. Word Break
// https://leetcode.com/problems/word-break/
/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:
The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        if (wordDict.size() == 0) {
            return false;
        }
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        records.clear();
        return helper(s, dict);
    }

private:
    unordered_map<string, bool> records;

    bool helper(const string &s, const unordered_set<string> &dict) {
        if (s.size() == 0) {
            return true;
        }
        if (records.find(s) != records.end()) {
            return records[s];
        }
        bool res = false;
        for (int i = 0; i < s.size(); ++i) {
            if (dict.find(s.substr(0, i - 0 + 1)) != dict.end() && helper(s.substr(i + 1), dict)) {
                res = true;
                break;
            }
        }
        records[s] = res;
        return res;
    }
};

int main() {
    string s = "applepenapple";
    vector<string> dict = {"apple", "pen"};
    cout << Solution().wordBreak(s, dict) << endl;
    return 0;
}
// Runtime: 12 ms, faster than 11.76% of C++ online submissions for Word Break.