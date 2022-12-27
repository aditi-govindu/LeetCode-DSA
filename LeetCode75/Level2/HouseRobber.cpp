/*
Q198. Description: You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        vector<int> profit;
        profit.push_back(nums[0]);
        // Start with maximum 0th or 1st house
        profit.push_back(nums[0] > nums[1] ? nums[0] : nums[1]);
        
        // Skip adjacent houses
        for(int i = 2; i < nums.size(); i++)
            profit.push_back(max(profit[i-2] + nums[i], profit[i-1]));
        return profit[nums.size() - 1];
    }
};