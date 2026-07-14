class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int profit = 0;
        int max_profit = 0;
        for (int sell = 1; sell < prices.size(); sell++) {
            profit = prices[sell] - prices[buy];
            if (profit < 0) {
                buy = sell;
            }
            else if (profit > max_profit) {
                max_profit = profit;
            }
        }
        return max_profit;
    }
};
