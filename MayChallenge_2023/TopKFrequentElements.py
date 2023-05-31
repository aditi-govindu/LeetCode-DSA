'''
Q347. Description: Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
'''

from collections import Counter

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        solution = []
        hashmap = Counter(nums)

        # Identify most common elements in hashmap
        sol = hashmap.most_common(k)
        for item in sol:
            solution.append(item[0])
        return solution