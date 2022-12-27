'''
Q3. Description: Given a string s, find the length of the longest substring without repeating characters.
'''
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start = 0
        result = 0
        hashmap = {}
        for end in range(len(s)):
            # If character at end of window seen in hashmap, delete repeating letter
            while s[end] in hashmap:
                val = s[start]
                del(hashmap[val])
                # Increment starting window by 1 to go to next letter
                start+=1
            # Add unique letter to hashmap
            hashmap[s[end]] = True
            # Longest substring is max of current length and longest seen so far
            result = max(result, len(hashmap))
        return result