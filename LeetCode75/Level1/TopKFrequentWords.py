'''
Q692. Description: Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
'''

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        hashmap = collections.Counter(words)
        # Sort hashmap in descending order and return k elements
        return sorted(list(hashmap.keys()), key=lambda x: (-hashmap[x], x))[:k]   