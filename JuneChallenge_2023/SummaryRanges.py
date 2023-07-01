'''
Q228. Description: You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
'''

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ranges = []
        n = len(nums)
        i = 0

        while i < n:
            start = nums[i]

            # If next number differs by 1, add it to the range
            while i + 1 < n and nums[i] + 1 == nums[i+1]:
                i += 1
            
            if start != nums[i]:
                ranges.append(str(start) + '->' + str(nums[i]))
            else:
                ranges.append(str(nums[i]))
            
            i += 1

        return ranges
