/*
Q2218. Description: There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.

In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.
*/

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        int n = piles.size();

        // dp stores leftmost piles, coins per pile
        vector dp(n + 1, vector<int>(k + 1));

        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= k; j++)
            {
                // Sum of coins taken from i-1 pile
                int currentSum = 0;
                for(int currCoins=0;currCoins <= min((int)piles[i - 1].size(), j);currCoins++)
                {
                    if(currCoins > 0)
                        currentSum += piles[i-1][currCoins - 1];
                    // Store optimal result in dp such that no more than k coins are chosen
                    dp[i][j] = max(dp[i-1][j - currCoins] + currentSum, dp[i][j]);
                }
            }
        }
        return dp[n][k];
    }
};