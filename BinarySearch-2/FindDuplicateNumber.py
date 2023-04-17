'''
Q287. Description: Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.
'''

from collections import Counter

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        hashmap = Counter(nums)
        for key, value in hashmap.items():
            if value > 1:
                return key