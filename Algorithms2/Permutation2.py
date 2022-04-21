'''
Q47. Description: Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
Eg: [1,1,2] = {[1,1,2] ; [1,2,1] ; [2,1,1]}
'''

from collections import Counter

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        # Create hashmap of elements and count of occurence in nums
        results = []
        
        def backtrack(comb, counter):
            # Store nums to backtrack later
            if len(comb) == len(nums):
                results.append(list(comb))
                return
            for num in counter:
                # Found, append number to comb and decrement hashmap to indicate considered
                if counter[num] > 0:
                    comb.append(num)
                    counter[num] -= 1
                    # Continue exploration, recursively
                    backtrack(comb, counter)
                    comb.pop()
                    counter[num] += 1
                    
        backtrack([], Counter(nums))
        return results