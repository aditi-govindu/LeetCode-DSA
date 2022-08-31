# Q578. Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        unique = set(nums)
        original_len = len(nums)
        unique_len = len(unique)
        # Check length of unique values is equal to that of original list. if yes, return false
        if original_len == unique_len:
            return False
        else:
            return True