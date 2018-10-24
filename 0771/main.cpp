#include <iostream>

using namespace std;

// 771. Jewels and Stones
// https://leetcode.com/problems/jewels-and-stones/
/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each
character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels. The letters
 in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:
Input: J = "aA", S = "aAAbbbb"
Output: 3

Example 2:
Input: J = "z", S = "ZZ"
Output: 0

Note:
    1. S and J will consist of letters and have length at most 50.
    2. The characters in J are distinct.
 */
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        for (const char &c : S) {
            if (J.find(c) != string::npos/*-1*/) {
                ++res;
            }
        }
        return res;
    }
};

int main() {
    int num = Solution().numJewelsInStones("aA", "aAAbbbb");
    cout << num << endl;
    return 0;
}
// Runtime: 4 ms, faster than 99.08% of C++ online submissions for Jewels and Stones.