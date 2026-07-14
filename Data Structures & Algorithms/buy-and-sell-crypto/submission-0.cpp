class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // one of the ideas we can use is a change per day
        // any day where we lose money will be necessarily worse than some other option
        // we can keep track of max profit until a loss
        // can also start by 
        // buy and sell pointer, keep track of difference between the two
        // max profit should be saved, indices not really necessary
        int buy = 0;
        int sell = 0;
        int profit = 0;
        int max_profit = 0;
        for (sell = 1; sell < prices.size(); sell++) {
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
