// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
// Author: Wangggod
// Date: 2020.3.4
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        auto min = prices[0];
        auto profit = 0;
        for (auto i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i -1]) {
                profit = max(profit, prices[i] - min);
            } else {
                min = std::min(min, prices[i]);;
            }
        }
        return profit;
    }
};
