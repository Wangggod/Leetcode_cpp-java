// Sourse: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/
// Author: Wangggod
// Date: 2020.3.5

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        auto profit = 0;
        for (auto i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i -1]) {
                profit = profit + prices[i]- prices[i-1];
            }
        }
        return profit;
    }
};
