#include <iostream>

using namespace std;

// 0709. To Lower Case
// https://leetcode.com/problems/to-lower-case/
class Solution {
public :
    string toLowerCase(string str) {
        for (char &c : str) {
            c = tolower(c);
        }
        return str;
    }
};

int main() {
    string res = Solution().toLowerCase("Guoliang");
    cout << res << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for To Lower Case.