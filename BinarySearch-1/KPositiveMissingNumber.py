'''
Q1539. Description: Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.
'''

class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        for i, n in enumerate(arr):
            if k <= n - i - 1:
                return i + k
        return k + len(arr)