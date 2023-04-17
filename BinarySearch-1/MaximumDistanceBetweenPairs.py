'''
Q1855. Description: You are given two non-increasing 0-indexed integer arrays nums1​​​​​​ and nums2​​​​​​.

A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - i​​​​.

Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.

An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length.
'''

class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        distance = 0
        i = 0
        j = 0

        while i < len(nums1) and j < len(nums2):
            if nums2[j] >= nums1[i]:
                distance = max(distance, j - i)

                # Move to next element in nums2 to maximize distance
                j += 1
            else:
                i += 1

                # Ensure i <= j
                if i > j:
                    j += 1
        return distance
