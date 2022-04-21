/*
Q213. Description: You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        // Dynamic programming to iterate over array, alternate houses
        for (int i = 2; i < nums.size() - 1; i++) 
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        int ans = dp[nums.size() - 2];
        dp[0]   = 0;
        dp[1]   = nums[1];
        for (int i = 2; i < nums.size(); i++)
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        return max(ans, dp[nums.size() - 1]);
    }
};