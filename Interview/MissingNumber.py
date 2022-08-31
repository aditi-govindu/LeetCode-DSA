'''
Q268. Description: Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
'''

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        given_sum = sum(nums)
        # AP sum of 1,2,3,4...n is n*(n+1)/2
        expected_sum = ((n)*(n+1))//2
        # Difference between sum of array and expected sum is the missing element
        return abs(given_sum - expected_sum)