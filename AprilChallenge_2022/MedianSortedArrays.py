'''
Q4. Description: Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
'''

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Store both arrays in nums3
        nums3 = nums1
        nums3.extend(nums2)
        # Sort in ascending order
        nums3.sort()
        n = len(nums3)
        mid = n//2
        # If even elements are present, return mean of middle and middle-1
        if n%2 == 0:
            return (nums3[mid] + nums3[mid-1])/2
        else:
            return nums3[mid]