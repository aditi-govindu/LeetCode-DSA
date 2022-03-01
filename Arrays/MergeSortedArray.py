# You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
# Q5. Merge 2 sorted arrays, in place with duplicates - Python inbuilt functions used
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # Consider only m elements of nums1 and n elements of nums2
        merged = nums1[:m] + nums2[:n]
        # Sort in place
        merged.sort()
        # Copy sorted array
        nums1[:] = merged