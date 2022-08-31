'''
Q546. Description: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice.
'''

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Hash map to keep track of (remaining value, considered number)
        seen = {}
        for index, value in enumerate(nums):
            rem = target - value
            if rem in seen:
                # Update hashmap with element as seen
                return(seen[rem], index)
            seen[value] = index