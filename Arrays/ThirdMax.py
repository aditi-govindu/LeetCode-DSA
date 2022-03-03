# Q14. Description: Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        buff = list()
        # Create unique list of nums
        for i, val in enumerate(nums):
            if val not in buff:
                buff.append(val)
        # Sort array in reverse order
        buff.sort(reverse = True)
        # Return maximum if length < 3
        if len(buff) <= 2:
            return buff[0]
        # Return 3rd largest element at index 2
        else:
            return buff[2]