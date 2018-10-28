// 38. Count and Say
// https://leetcode.com/problems/count-and-say/
/*
The count-and-say sequence is the sequence of integers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string s = countAndSay(n - 1);
        string res;
        char ch = '0';
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (ch != s[i]) {
                if (count > 0) {
                    res += to_string(count);
                    res += ch;
                    count = 0;
                }
            }
            ch = s[i];
            ++count;
        }
        if (count > 0) {
            res += to_string(count);
            res += ch;
        }
        return res;
    }
};

int main() {
    cout << Solution().countAndSay(5) << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count and Say.