'''
Q152. Description: Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.
'''
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # If array has 2 elements and zero is 1 of them, result is other element
        result = max(nums)
        
        curMax, curMin = 1, 1
        
        for num in nums:
            if num == 0:
                # If 0 seen, reset curMin and curMax to 1 to look for next elements
                curMax, curMin = 1, 1
                continue
                
            curr = curMax * num
            curMax = max(curr, curMin * num, num)
            curMin = min(curr, curMin * num, num)
            result = max(result, curMax)
        return result