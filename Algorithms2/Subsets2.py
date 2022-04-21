'''
Q90. Description: Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
'''

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        powerset = 2**len(nums)
        s = set()
        
        # Time complexity is 2^N * N
        for counter in range(0, powerset):
            results = []
            for j in range(0, len(nums)):
                # If bit is 1, consider element in powerset
                if(counter & (1 << j) > 0):
                    results.append(nums[j])
            # Add result to a set, so unique collection is generated
            s.add(tuple(results))
        return s