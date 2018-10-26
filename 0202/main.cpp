// 202. Happy Number
// https://leetcode.com/problems/happy-number/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> record;
        record.insert(n);

        while (true) {
            int m = digitSquareSum(n);
            if (m == 1) {
                return true;
            }
            if (record.find(m) != record.end()) {
                return false;
            }
            record.insert(m);
            n = m;
        }
    }

private:
    int digitSquareSum(int n) {
        int sum = 0, temp;
        while (n) {
            temp = n % 10;
            sum += temp * temp;
            n /= 10;
        }
        return sum;
    }
};

int main() {
    cout << Solution().isHappy(19) << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Happy Number.