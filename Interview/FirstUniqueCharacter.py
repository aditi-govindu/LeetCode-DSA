'''
Q387. Description: Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
'''

class Solution:
    def firstUniqChar(self, s: str) -> int:
        # Create hashmap of count of all characters in s
        hashmap = collections.Counter(s)
        for index, letter in enumerate(s):
            # If character 1 time, return index
            if hashmap[letter] == 1:
                return index
        return -1