'''
Q18. Description: Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
'''

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        def Ksum(nums, target, k) -> List[List[int]]:
            result = []
            
            # If nums is empty, return result
            if not nums:
                return result
            
            # Find average of k values
            average_value = target//k
            
            # No solution if average of numbers < target
            if average_value < nums[0] or nums[-1] < average_value:
                return result
            
            # If k is 2, perform TwoSum logic
            if k == 2:
                return TwoSum(nums, target)
            
            # Recursively split the nums list into TwoSum type problem
            for i in range(len(nums)):
                if i == 0 or nums[i-1] != nums[i]:
                    for subset in Ksum(nums[i+1:], target - nums[i], k-1):
                        result.append([nums[i]] + subset)
            return result
        
        def TwoSum(nums, target) -> List[List[int]]:
            res = []
            start, end = 0, len(nums) - 1
            while start < end:
                curr = nums[start] + nums[end]
                # If sum less than target or duplicate found move left pointer 
                if curr < target or (start > 0 and nums[start] == nums[start - 1]):
                    start += 1
                # If sum greater than target or duplicate found move right pointer 
                elif curr > target or (end < len(nums) - 1 and nums[start] == nums[end + 1]):
                    end -= 1
                else:
                    # Found a pair, move both pointers
                    res.append([nums[start], nums[end]])
                    start += 1
                    end -= 1
            return res
        
        nums.sort()
        return Ksum(nums, target, 4)   