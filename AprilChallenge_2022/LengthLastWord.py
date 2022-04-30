'''
Q58. Description: Given a string s consisting of some words separated by some number of spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.
'''

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # Remove trailing spaces on left and right
        s = s.strip()
        # Split words based on space
        values = s.split(" ")
        # Return length of last word
        return(len(values[-1]))