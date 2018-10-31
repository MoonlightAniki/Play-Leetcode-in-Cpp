// 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/
/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:
Input:
"tree"
Output:
"eert"
Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input:
"cccaaa"
Output:
"cccaaa"
Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input:
"Aabb"
Output:
"bbAa"
Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        if (s.size() <= 2) {
            return s;
        }
        unordered_map<char, int> freq;
        vector<string> bucket(s.size() + 1, "");//bucket[index]表示出现次数为index的字符组成的字符串
        for (const char &c : s) {
            ++freq[c];
        }
        for (const pair<char, int> &p : freq) {
            int n = p.second;
            int c = p.first;
            bucket[n].append(n, c);
        }
        string res;
        for (int i = bucket.size() - 1; i > 0; --i) {
            res.append(bucket[i]);
        }
        return res;
    }
};

int main() {
    cout << Solution().frequencySort("abbcccddd") << endl;
    return 0;
}
// Runtime: 16 ms, faster than 60.51% of C++ online submissions for Sort Characters By Frequency.