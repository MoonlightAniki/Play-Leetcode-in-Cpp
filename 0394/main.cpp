// 394. Decode String
// https://leetcode.com/problems/decode-string/
/*
Given an encoded string, return it's decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<char> records;
        for (int i = 0; i < s.size(); ++i) {

            // 如果不是右括号加入栈中
            if (s[i] != ']') {
                records.push(s[i]);
            }
                // 是右括号的话，开始从栈内出栈字符
            else {
                // 先获取要重复的字符串
                string str;
                while (records.top() != '[') {
                    str = records.top() + str;
                    records.pop();
                }

                // 将左括号出栈
                records.pop();

                // 获取要重复的次数
                int fact = 1;
                int count = 0;
                while (!records.empty() && isdigit(records.top())) {//注意检查栈内是否还有元素
                    count += ((records.top()) - '0') * fact;
                    records.pop();
                    fact *= 10;
                }

                // 将count个str重新加入栈内
                for (int j = 0; j < count; ++j) {
                    for (const char &c : str) {
                        records.push(c);
                    }
                }
            }
        }

        // 将栈内元素拼接成字符串返回
        string res;
        while (!records.empty()) {
            res = records.top() + res;
            records.pop();
        }
        return res;
    }
};

int main() {
    cout << Solution().decodeString("3[a]2[bc]") << endl;
    cout << Solution().decodeString("3[a2[c]]") << endl;
    cout << Solution().decodeString("2[abc]3[cd]ef") << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.