// 小米面试题
// 美丽字符串：(1)字符串中所有字符出现的次数相等
//            (2)删除或者添加一个字符使所有字符出现的次数相等
// 满足以上条件之一的字符串称为美丽字符串
// "abcabc" 满足条件(1)
// "aabbccc" 满足条件(2)
// "aabbc" 满足条件(2)

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isBeautiful(string s) {
        if (s.size() == 0) {
            return true;
        }
        unordered_map<char, int> freq;
        for (const char &c : s) {
            ++freq[c];
        }
        vector<vector<char>> bucket(s.size() + 1);
        for (auto &p : freq) {
            char c = p.first;
            int count = p.second;
            bucket[count].push_back(c);
        }
        int notEmptyCount = 0;
        int index = -1;
        for (int i = 0; i < bucket.size(); ++i) {
            if (bucket[i].size() != 0) {
                if (++notEmptyCount == 3) {
                    return false;
                }
                if (index == -1) {
                    index = i;
                }
            }
        }
        if (notEmptyCount == 0) {
            return false;
        }
        if (notEmptyCount == 1) {
            return true;
        }
        // notEmptyCount==2
        if (bucket[index + 1].size() == 0) {
            return false;
        }
        return bucket[index].size() == 1 || bucket[index + 1].size() == 1;
    }
};

int main() {
    Solution s = Solution();
    cout << s.isBeautiful("aabbcc") << endl;
    cout << s.isBeautiful("aabbccc") << endl;
    cout << s.isBeautiful("aabbc") << endl;
    cout << s.isBeautiful("aabbcccddd") << endl;
    cout << s.isBeautiful("aabbcddd") << endl;
    cout << s.isBeautiful("") << endl;
    return 0;
}