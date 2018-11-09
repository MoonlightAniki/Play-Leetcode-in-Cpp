// 309. Best Time to Buy and Sell Stock with Cooldown
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell
one share of the stock multiple times) with the following restrictions:
    You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

Example:
Input: [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
 */

#include <iostream>
#include <vector>

using namespace std;

// Time Limit Exceeded
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        memo = vector<int>(prices.size(), -1);
        int l = 0;
        int r = prices.size() - 1;
        return __maxProfit(prices, l, r);
    }

private:
    vector<int> memo;

    int __maxProfit(const vector<int> &prices, int l, int r) {
        if (l >= r) {
            return 0;
        }
        if (memo[l] != -1) {
            return memo[l];
        }
        int res = 0;
        for (int i = l; i <= r; ++i) {
            for (int j = i + 1; j <= r; ++j) {
                if (prices[j] > prices[i]) {
                    res = max(res, prices[j] - prices[i] + __maxProfit(prices, j + 2, r));
                }
            }
        }
        memo[l] = res;
        return res;
    }
};

int main() {
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << Solution().maxProfit(prices) << endl;

    prices = {1, 2};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}