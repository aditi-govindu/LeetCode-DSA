'''
Q567. Description: Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.
'''
from collections import Counter

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # If s2 < s1, no permutations can be found
        if len(s1) > len(s2):
            return False
        # Create hashmap of letters in s1
        hashmap1 = Counter(s1)
        hashmap2 = Counter()
        for i, letter in enumerate(s2):
            # Add letter to hashmap for s2
            hashmap2[letter] += 1
            # If index of character > length of s1, remove extra characters in hashmap of s2
            if i >= len(s1):
                remove_letter = s2[i-len(s1)]
                hashmap2[remove_letter] -= 1
            # If permutation of s1 found in s2, return true
            if hashmap2 == hashmap1:
                return True
        return False
            