'''
Q16. Description: Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
'''
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n = len(nums)
        nums.sort()
        closest = float('-inf')
        
        for i in range(n-2):
            left = i + 1
            right = n - 1
            
            while left < right:
                curr = nums[left] + nums[i] + nums[right]
                
                if abs(curr - target) < abs(target - closest):
                    closest = curr
                
                if curr == target:
                    return curr
                elif curr < target:
                    left += 1
                else:
                    right -= 1
        return closest