// 676. Implement Magic Dictionary
// https://leetcode.com/problems/implement-magic-dictionary/
/*
Implement a magic directory with buildDict, and search methods.
For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.
For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.

Example 1:
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False

Note:
You may assume that all the inputs are consist of lowercase letters a-z.
For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across multiple test cases. Please see here for more details.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 使用
class MagicDictionary {

private:
    unordered_map<int, vector<string>> records;

public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        records.clear();
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string word : dict) {
            if (records.find(word.size()) == records.end()) {
                records[word.size()] = vector<string>();
            }
            records[word.size()].push_back(word);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        if (records.find(word.size()) == records.end()) {
            return false;
        }
        for (const string &s : records[word.size()]) {
            if (isMagicSame(s, word)) {
                return true;
            }
        }
        return false;
    }

private:
    // 当字符串a和b只有一个字符不同为真
    bool isMagicSame(const string &a, const string &b) {
        if (a == b) return false;
        int diffCount = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                ++diffCount;
                if (diffCount > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

void printBoolean(bool b) {
    cout << (b ? "True" : "False") << endl;
}

int main() {
    vector<string> dict = {"hello", "hallo", "leetcode", "judge"};
    MagicDictionary md = MagicDictionary();
    md.buildDict(dict);
    printBoolean(md.search("hello"));//True
    printBoolean(md.search("helle"));//True
    printBoolean(md.search("hell"));//False
    printBoolean(md.search("leetcodd"));//True
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Magic Dictionary.