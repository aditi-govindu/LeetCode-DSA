'''
Q1027. Description: Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

Note that:

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).
'''

class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        dp = {}

        for right in range(len(nums)):
            for left in range(0, right):
                # Store elements in a hashmap where map[difference] = elements
                dp[(right, nums[right] - nums[left])] = dp.get((left, nums[right] - nums[left]), 1) + 1   
        
        # Get longest length of hashmap sequence
        return max(dp.values())