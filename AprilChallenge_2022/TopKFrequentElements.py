'''
Q347. Description: Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
'''

from collections import Counter

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        solution = []
        # Create hashmap of item and count in nums
        hashmap = Counter(nums)
        # Use inbuilt function to find most common elements
        sol = hashmap.most_common(k)
        # Append item from tuple, that is - (item, count)
        for item in sol:
            solution.append(item[0])
        return solution