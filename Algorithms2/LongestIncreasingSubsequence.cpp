/*
Q300. Description: Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. 

For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> dp(n,1);
        
        for(int i=1; i<n; i++)
        {
            int m=0;
            for(int j=0; j<i; j++)
            {
                // If next number is smaller, update max
                if(nums[j] < nums[i])
                    m=max(m,dp[j]);
            }
            dp[i]=m+1;
        }
        return *max_element(dp.begin(),dp.end());
    }
};