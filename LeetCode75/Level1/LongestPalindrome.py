'''
Q409. Description: Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
'''

class Solution:
    def longestPalindrome(self, s: str) -> int:
        count = collections.Counter(s)
        result = 0
        
        for key, value in count.items():
            # Try to pair all letters in string
            result += value // 2 * 2
            # Check all letters partnered if yes then check for unique center
            if result % 2 == 0 and value % 2 == 1:
                result += 1
        return result
                    