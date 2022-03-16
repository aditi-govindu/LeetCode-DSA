'''
Q557. Description: Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
'''

class Solution:
    def reverseWords(self, s: str) -> str:
        ans = ""
        for i in s.split(" "):
            # Reverse every word in the string and append to ans, with whitespace
            ans = ans + (i[::-1]) + " "
        # Strip trailing white space
        return ans.rstrip()