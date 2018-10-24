// 344. Reverse String
// https://leetcode.com/problems/reverse-string/

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
        return s;
    }
};

int main() {
    cout << Solution().reverseString("hello") << endl;
    return 0;
}
// Runtime: 8 ms, faster than 75.73% of C++ online submissions for Reverse String.