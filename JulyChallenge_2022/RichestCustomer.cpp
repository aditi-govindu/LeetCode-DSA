/*
Q1672. Description: You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i customer has in the j bank. Return the wealth that the richest customer has.
A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.
*/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int m = size(accounts);
        int n = size(accounts[0]);
        int max_wealth = -1;
        
        for(int row = 0; row < m; row++)
        {
            int curr_wealth = 0;
            for(int col = 0; col < n; col++)
            {
                curr_wealth += accounts[row][col];
            }
            if(max_wealth < curr_wealth)
                max_wealth = curr_wealth;
        }
        return max_wealth;
    }
};