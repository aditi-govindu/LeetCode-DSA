'''
Q.242 Description: Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
'''

# Import modules
from collections import Counter

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:  
        # Store hashmap of strings s and t
        letters = Counter(s)
        anagram = Counter(t)
        # If hashmap letters and counts are equal, return true. Else return false
        return letters == anagram
        