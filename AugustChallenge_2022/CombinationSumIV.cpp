/*
Q377. Description: Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.
*/

class Solution {
public:
    vector<int> dp;
    int CountPairs(vector<int>&nums, int T, int n)
    {
        // End of combination reached. Return 1
        if(T == 0)
            return 1;
        int ans = 0;
        
        if(dp[T] != -1)
            return dp[T];
        
        for(int i = 0; i < n; i++)
        {
            // Store all pairs whose sum is less than equal to target
            if(nums[i] <= T)
                ans += CountPairs(nums, T-nums[i], n);
        }
        return dp[T] = ans;    
    }
    
    int combinationSum4(vector<int>& nums, int target) 
    {
        int n = size(nums);
        dp.resize(target+1, -1);
        return CountPairs(nums, target, n);
    }
};