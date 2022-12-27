/*
Q70. Description: You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

int climbStairs(int n)
{
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 2;
    // Fibonacci series where count of steps are 1 or 2 and increase incrementally
    for(int i = 2; i < n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n-1];
}