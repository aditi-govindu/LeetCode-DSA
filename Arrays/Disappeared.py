# Q15. Description: Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        # Create unique list of numbers
        unique = set(nums)
        ans = list()
        # Loop over all numbers in range 1 to n
        for i in range(1, len(nums)+1):
            # If number not seen in list, append to final answer
            if i not in unique:
                ans.append(i)
        return ans