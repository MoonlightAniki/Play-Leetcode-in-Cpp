// 344. Reverse String
// https://leetcode.com/problems/reverse-string/

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        string res;
        for (int i = s.size() - 1; i >= 0; --i) {
            res.push_back(s[i]);
        }
        return res;
    }
};

int main() {
    cout << Solution().reverseString("hello") << endl;
    return 0;
}
// Runtime: 8 ms, faster than 75.73% of C++ online submissions for Reverse String.