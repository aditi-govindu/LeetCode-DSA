/*
Q673. Description: Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1), count(n,1);
        int m = 1;
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                // If next number is smaller, update max
                if(nums[j] < nums[i])
                {
                    if(dp[i] == dp[j]+1)
                        count[i] += count[j];
                    else if (dp[i] < dp[j]+1)
                    {
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    }
                }
            }
            m=max(m, dp[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(dp[i] == m)
                ans += count[i];
        }
        return ans;
    }
};