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
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }

        // buy[i]表示第i天以买入结束能获得的最大值
        // sell[i]表示第i天以卖出结束能获得的最大值
        // rest[i]表示第i天以休息结束能获得的最大值
        // buy[i] = max(buy[i-1], rest[i-1]-price[i])      -------(1)
        // sell[i] = max(sell[i-1], buy[i-1]+price[i])     -------(2)
        // rest[i] = max(rest[i-1], buy[i-1], sell[i-1])   -------(3)
        // rest[i] >= buy[i]                               -------(4)
        // rest[i] <= sell[i]                              -------(5)
        // 由(3)(4)得到 rest[i] = max(rest[i-1],sell[i-1])  -------(6)
        // 由(5)(6)得到 rest[i] = sell[i-1]                 -------(7)
        // 由(1)(2)(7)得到以下两个等式

        // buy[i] = max(buy[i-1], sell[i-2]-price[i])
        // sell[i] = max(sell[i-1], buy[i-1]+price[i])
        vector<int> buy(n, INT_MIN);
        vector<int> sell(n, 0);

        buy[0] = -prices[0];
        buy[1] = max(buy[0], -prices[1]);
        sell[0] = 0;
        sell[1] = max(sell[0], buy[0] + prices[1]);
        for (int i = 2; i < n; ++i) {
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        return sell.back();
    }
};

int main() {
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << Solution().maxProfit(prices) << endl;

    prices = {1, 2};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}
// Runtime: 4 ms, faster than 99.73% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.