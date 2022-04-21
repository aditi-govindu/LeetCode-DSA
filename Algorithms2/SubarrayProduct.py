'''
Q713. Description: Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
'''

class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0
        prod = 1
        ans = 0
        left = 0
        for right, val in enumerate(nums):
            # Keep multiplying left values till product > target
            prod *= val
            while prod >= k:
                # Divide product by last multiplied value
                prod /= nums[left]
                # Increment start by 1
                left += 1
            ans += right - left + 1
        return ans