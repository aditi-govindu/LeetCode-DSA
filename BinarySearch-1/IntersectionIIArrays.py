# Q350. Description: Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        common = []

        for num in nums1:
            if num in nums2:
                common.append(num)
                nums2.remove(num)
        
        return common