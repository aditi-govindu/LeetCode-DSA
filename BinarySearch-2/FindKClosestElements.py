'''
Q658. Description: Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
'''

class Solution:
    def findClosestElements(self, A: List[int], k: int, x: int) -> List[int]:
        left, right = 0, len(A) - k
        while left < right:
            mid = (left + right) // 2
            if x - A[mid] > A[mid + k] - x:
                left = mid + 1
            else:
                right = mid
        return A[left:left + k]