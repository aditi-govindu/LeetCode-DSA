'''
Q416. Description: Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
'''

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 == 1:
            # Odd sum cannot be partitioned
            return False
        
        target = total // 2
        
        dp = [False] * (target + 1)
        dp[0] = True
        
        for num in nums:
            for i in range(len(dp) - 1, num - 1, -1):
                dp[i] = dp[i] or dp[i - num]
        return dp[-1]
        