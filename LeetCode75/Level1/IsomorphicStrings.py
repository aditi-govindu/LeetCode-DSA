'''
Q205. Description: Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
'''
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        n = len(s)
        hashmap = {}
        
        for i in range(n):
            # If letter not in dictionary, check for its pair. If found, invalid mapping
            if s[i] not in hashmap.keys():
                if t[i] in hashmap.values():
                    return False
                else:
                    hashmap[s[i]] = t[i]
            else:
                if hashmap[s[i]] != t[i]:
                    return False
        return True