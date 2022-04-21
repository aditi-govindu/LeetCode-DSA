'''
Q153. Description: Suppose an array of length n sorted in ascending order is rotated between 1 and n times. Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.
'''

class Solution:
    def findMin(self, nums: List[int]) -> int:
        return min(nums)