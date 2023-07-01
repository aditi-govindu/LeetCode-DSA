/*
Q714. Description: You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int profit = 0;
        int hold = -prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            // Update profit as maximum sp - cp - fees paid
            profit = max(profit, hold + prices[i] - fee);
            // Update hold or cp as maximum profit - price paid
            hold = max(hold, profit - prices[i]);
        }
        return profit;
    }
};