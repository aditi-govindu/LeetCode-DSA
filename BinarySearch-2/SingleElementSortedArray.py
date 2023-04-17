'''
Q540. Description: You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.
'''

from collections import Counter

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        count = Counter(nums)
        for k, v in count.items():
            if v == 1:
                return k