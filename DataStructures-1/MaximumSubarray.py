# Q53. Description: Given an integer array nums, find the subarray which has the largest sum and return its sum.

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        maxSum = nums[0]
        current = 0
        
        for i in range(n):
            current += nums[i]
            maxSum = max(current, maxSum)
            current = max(current, 0)
        
        return maxSum
        