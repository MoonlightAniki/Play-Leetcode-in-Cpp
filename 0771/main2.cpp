#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        for (const char &c : J) {
            jewels.insert(c);
        }
        int res = 0;
        for (const char &c : S) {
            if (jewels.find(c) != jewels.end()) {
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