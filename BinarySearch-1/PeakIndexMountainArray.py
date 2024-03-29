'''
Q852. Description: An array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.
'''

class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        # Once element greater than current is seen, peak reached
        for i in range(len(arr) - 1):
            if arr[i] > arr[i + 1]:
                return i