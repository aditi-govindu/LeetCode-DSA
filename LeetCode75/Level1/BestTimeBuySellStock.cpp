/*
Q121. Description: You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0)
            return 0;
        int profit = 0;
        int high = prices[0];
        int low = prices[0];
        
        for(int i = 0; i < n; i++)
        {
            // If current cost < cost price, find profit and update low, high
            if(prices[i] < low)
            {
                profit = max(profit, high-low);
                low = prices[i];
                high = prices[i];
            }
            else
                high = max(prices[i], high);
        }
        // Profit is max of all values and last difference
        profit = max(profit, high - low);
        return profit;
    }
};