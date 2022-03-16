'''
Q77. Description: Given two integers n and k, return all possible combinations of k numbers out of the range [1, n]. You may return the answer in any order.
Example: n = 4, k = 2 gives [1,2] [1,3] [1,4] [2,3] [2,4] [3,4]
'''

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        # Create a list of all values in range [1,n]
        numbers = [i for i in range(1,n+1)]
        result = self.RecursiveCombine(numbers,k)
        return result
        
    def RecursiveCombine(self, values, count):
        if count == 0:
            return [[]]
        ans = []
        for index, val in enumerate(values):
            element = val
            # Considered element, hence removed from list of numbers to chose from
            numbers_left = values[index+1:]
            # Recursively add k-1 elements to array from remaining numbers
            for element2 in self.RecursiveCombine(numbers_left, count-1):
                ans.append([element]+element2)
        return ans
    
'''
Solution 2: USING INBUILT FUNCTIONS
from itertools import combinations

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        numbers = []
        for i in range(1,n+1):
            numbers.append(i)
        return list(combinations(numbers,k))
'''