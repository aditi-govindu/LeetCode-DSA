'''
Q15. Description: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
'''

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        for i in range(len(nums)):
            # If duplicates seen, continue
            if i > 0 and nums[i] == nums[i-1]:
                continue
            # Target is all numbers left, with negative sign
            target = nums[i]*-1
            start = i+1
            end = len(nums)-1
            while start < end:
                if nums[start] + nums[end] == target:
                    result.append([nums[i], nums[start], nums[end]])
                    start += 1
                    # Skip duplicates from start side
                    while start < end and nums[start] == nums[start - 1]:
                        start = start + 1
                elif nums[start] + nums[end] < target:
                    start = start+1
                else:
                    end = end - 1
        return result   