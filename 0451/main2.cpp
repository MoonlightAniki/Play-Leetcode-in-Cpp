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
#include <map>

using namespace std;

// Memory Limit Exceeded
class Solution {
public:
    string frequencySort(string s) {
        if (s.size() <= 2) {
            return s;
        }
        unordered_map<char, int> c2i;
        multimap<int, char> i2c;
        for (const char &c : s) {
            ++c2i[c];
        }
        for (const pair<char, int> &p : c2i) {
            i2c.insert(make_pair(p.second, p.first));
        }
        string res;
        for (const pair<int, char> &p : i2c) {
            for (int i = 0; i < p.first; ++i) {
                res = p.second + res;
            }
        }
        return res;
    }
};

int main() {
    cout << Solution().frequencySort("abbcccddd") << endl;
    return 0;
}