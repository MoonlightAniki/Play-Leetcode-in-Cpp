// 720. Longest Word in Dictionary
// https://leetcode.com/problems/longest-word-in-dictionary/
/*
Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character
at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.
If there is no answer, return the empty string.

Example 1:
Input:
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation:
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

Example 2:
Input:
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation:
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".

Note:
    1. All the strings in the input will only contain lowercase letters.
    2. The length of words will be in the range [1, 1000].
    3. The length of words[i] will be in the range [1, 30].
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string longestWord(vector<string> &words) {
        sort(words.begin(), words.end());
        unordered_set<string> record;
        record.insert("");
        string res;
        for (const string &word : words) {
            if (record.find(word.substr(0, word.size() - 1)) != record.end()) {
                record.insert(word);
                res = word.size() > res.size() ? word : res;
            }
        }
        return res;
    }
};

int main() {
//    vector<string> words = {"w", "wo", "wor", "worl", "world"};
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << Solution().longestWord(words) << endl;
    return 0;
}
// Runtime: 32 ms, faster than 93.95% of C++ online submissions for Longest Word in Dictionary.