'''
Q438. Description: Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
'''

from collections import Counter

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        hashmap = dict(Counter(p))
        res = []
        if len(p) > len(s):
            return res
        
        # Decrement hashmap value for character seen in string s
        for i in range(len(p)-1):
            if s[i] in hashmap.keys():
                hashmap[s[i]] -= 1
                
        for i in range(-1, len(s)-len(p)+1):
            # Increment count if letter moves outside window
            if i > -1 and s[i] in hashmap.keys():
                hashmap[s[i]] += 1
            if i+len(p) < len(s) and s[i+len(p)] in hashmap.keys():
                hashmap[s[i+len(p)]] -= 1
            # If value of characters is 0, anagram seen in string
            if all(v==0 for v in hashmap.values()):
                res.append(i+1)
        return res           