/*
Q322. Description: You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int solution[amount+1];
        solution[0] = 0;
        // Initialize solution array to amount + 1
        for(int i = 1; i <= amount; i++)
            solution[i] = amount + 1;
        for(int i =0; i < coins.size(); i++)
        {
            // if coin value less than amount, add to solution array
            if(coins[i] <= amount)
                solution[coins[i]] = amount;
        }
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                // If difference in amount is greater than 0, add minimum change to solution
                if(i - coins[j] >= 0)
                    solution[i] = min(solution[i], 1+solution[i-coins[j]]);
            }
        } 
        // If last value is equal to amount, no solution found
        return (solution[amount] == amount + 1) ? -1 : solution[amount];
    }
};