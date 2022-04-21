'''
Q78. Description: Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
'''

class Solution:        
    def subsets(self, nums: List[int]) -> List[List[int]]:
        powerset = 2**len(nums)
        # Iterate over (2^N) * N times
        for counter in range(0, powerset):
            results = []
            for j in range(0, len(nums)):
                # If bit is 1, consider element in powerset
                if(counter & (1 << j) > 0):
                    results.append(nums[j])
            # yield ensures solution is updated after every iteration
            yield results        