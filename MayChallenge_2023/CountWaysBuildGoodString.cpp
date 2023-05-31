/*
Q2466. Description: Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.
*/
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        int mod = 1000000007;
        vector<int>dp(high + 1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= high; i++)
        {
            // If current end is more than 0, append even length count
            if(i >= zero)
                dp[i] += dp[i - zero];
            // If current end is more than 1, append odd length count
            if(i >= one)
                dp[i] += dp[i - one];
            dp[i] %= mod;   
        }

        int answer = 0;
        // Add strings with valid length
        for(int j = low; j <= high; j++)
        {
            answer += dp[j];
            answer %= mod;
        }
        return answer;
    }
};