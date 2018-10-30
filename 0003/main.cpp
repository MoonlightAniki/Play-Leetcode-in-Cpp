// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) {
            return s.size();
        }
        int freq[256] = {0};
        int left = 0;
        int right = -1;
        int res = 0;
        while (left < s.size()) {
            if (right + 1 < s.size() && freq[s[right + 1]] == 0) {
                ++freq[s[++right]];
            } else {
                --freq[s[left++]];
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

int main() {
//    cout << Solution().lengthOfLongestSubstring("pwwkew") << endl;
    cout << Solution().lengthOfLongestSubstring("tmmzuxt") << endl;
    return 0;
}
// Runtime: 16 ms, faster than 92.35% of C++ online submissions for Longest Substring Without Repeating Characters.