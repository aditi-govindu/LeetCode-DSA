# Q217. Description: Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

from collections import Counter

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # Create hashmap of numbers
        seen = Counter(nums)
        # If any number seen more than twice, return true
        for k, v in seen.items():
            if v >= 2:
                return True
        return False