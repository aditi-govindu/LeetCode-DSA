'''
Q198. Description: You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
'''

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return max(nums)
        profit = {}
        # Index 0 holds even start point
        profit[0] = nums[0]
        # Index 1 stores maximum value at even or odd start point
        profit[1] = max(nums[0], nums[1])
        
        for i in range(2, len(nums)):
            # Store even+even and odd+odd sums
            profit[i] = nums[i] + profit[i-2]
            # Compare value with previous maximum
            profit[i] = max(profit[i], profit[i-1])
        # Largest value is stored at end of profit hashmap    
        return profit[len(profit)-1]