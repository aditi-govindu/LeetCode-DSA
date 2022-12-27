'''
Q438. Description: Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
'''

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        hashmap = collections.Counter(p)
        res = []
        # If permutations greater than original string
        if len(p) > len(s):
            return res
                        
        for i in range(len(p)-1):
            # Decrement hashmap count if letter matched
            if s[i] in hashmap.keys():
                hashmap[s[i]] -= 1
                
        for i in range(-1, len(s)-len(p)+1):
            # Traverse string in reverse and check if permutation found
            if i > -1 and s[i] in hashmap.keys():
                hashmap[s[i]] += 1
            if i+len(p) < len(s) and s[i+len(p)] in hashmap.keys():
                hashmap[s[i+len(p)]] -= 1
            if all(v==0 for v in hashmap.values()):
                res.append(i+1)
        return res  
        