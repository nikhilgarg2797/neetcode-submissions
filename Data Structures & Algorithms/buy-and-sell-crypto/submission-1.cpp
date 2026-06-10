class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_index = 0;
        int max_profit = 0;
        for(int day = 1; day < prices.size(); day++)
        {
            if(prices[day] < prices[buy_index]) buy_index = day;
            else    max_profit = max(max_profit, prices[day] - prices[buy_index]);
        }
        return max_profit;
    }
};