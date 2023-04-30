'''
Q2439. Description: You are given a 0-indexed array nums comprising of n non-negative integers.

In one operation, you must:

Choose an integer i such that 1 <= i < n and nums[i] > 0.
Decrease nums[i] by 1.
Increase nums[i - 1] by 1.
Return the minimum possible value of the maximum integer of nums after performing any number of operations.
'''

class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        prefixSum = [num for num in nums]

        # Compute prefix sum of array
        for i in range(1, len(nums)):
            prefixSum[i] = prefixSum[i - 1] + nums[i]
        
        ans = 0
        for i in range(len(nums)):
            # Store minimum of maximum sum in the array
            if prefixSum[i] % (i + 1) != 0:
                ans = max(ans, (prefixSum[i] // (i + 1) + 1))
            else:
                ans = max(ans, prefixSum[i] // (i+1))

        return ans