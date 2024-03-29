'''
Q137. Description: Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.
'''

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hashmap = {}

        for n in nums:
            hashmap[n] = hashmap.get(n, 0) + 1
        
        for k, v in hashmap.items():
            if v == 1:
                return k
        