'''
Q46. Description: Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
'''
from itertools import permutations

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        #return list(permutations(nums))
        result = self.RecursivePermute(nums)
        return result
    def RecursivePermute(self, values):
        if len(values) == 0:
            return [[]]
        ans = []
        for index, val in enumerate(values):
            element = val
            # Considered element, hence removed from list of numbers to chose from
            numbers_left = values[index+1:] + values[:index]
            # Recursively add remaining elements to array from numbers
            for element2 in self.RecursivePermute(numbers_left):
                ans.append([element]+element2)
        return ans