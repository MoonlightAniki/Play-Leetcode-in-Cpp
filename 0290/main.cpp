// 290. Word Pattern
// https://leetcode.com/problems/word-pattern/
/*
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:
Input: pattern = "abba", str = "dog cat cat dog"
Output: true

Example 2:
Input:pattern = "abba", str = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false

Example 4:
Input: pattern = "abba", str = "dog dog dog dog"
Output: false

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        split(str, words);
        if (pattern.size() != words.size()) {
            return false;
        }
        unordered_map<char, int> patternMap;
        unordered_map<string, int> wordMap;
        for (int i = 0; i < pattern.size(); ++i) {
            if (patternMap[pattern[i]] != wordMap[words[i]]) {
                return false;
            }
            patternMap[pattern[i]] = i + 1;
            wordMap[words[i]] = i + 1;
        }
        return true;
    }

private:
    void split(const string &s, vector<string> &words, const char flag = ' ') {
        istringstream ss(s);
        string temp;
//        while (getline(ss, temp, flag)) {
//            words.push_back(temp);
//        }
        while (ss >> temp) {
            words.push_back(temp);
        }
    }
};

int main() {
    cout << Solution().wordPattern("abba", "dog cat cat dog") << endl;
    cout << Solution().wordPattern("aaaa", "dog cat cat dog") << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Word Pattern.