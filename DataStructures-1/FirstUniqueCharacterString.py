'''
Q387. Description: Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
'''

class Solution:
    def firstUniqChar(self, s: str) -> int:
        hashmap = collections.Counter(s)
        for key, val in hashmap.items():
            if val == 1:
                return s.index(key)
        return -1
        