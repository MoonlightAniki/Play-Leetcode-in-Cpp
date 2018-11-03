// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        if (digits.size() == 0) {
            return res;
        }
        string solution;
        backtrack(digits, 0, solution);
        return res;
    }

private:
    unordered_map<char, string> digit_to_string = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
    };

    vector<string> res;

    void backtrack(const string &digits, int index, string &solution) {
        if (solution.size() == digits.size()) {
            res.push_back(solution);
            return;
        }
        for (int i = index; i < digits.size(); ++i) {
            string s = digit_to_string[digits[i]];
            for (int j = 0; j < s.size(); ++j) {
                solution.push_back(s[j]);
                backtrack(digits, i + 1, solution);
                solution.pop_back();
            }
        }
    }
};

int main(void) {
    vector<string> res = Solution().letterCombinations("23");
    for (auto s : res) {
        cout << s << endl;
    }
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.