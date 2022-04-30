'''
Q680. Description: Given a string s, return true if the s can be palindrome after deleting at most one character from it.
'''

class Solution:
    def validPalindrome(self, s: str) -> bool:
        def palindrome(start, end, s):
            # Check if character at start is equal to that at end
            while(start < end):
                if s[start] != s[end]:
                    return False
                start+=1
                end-=1
            return True
        
        # Driver code
        start = 0
        end = len(s) - 1
        while(start < end):
            # If characters not equal, delete at front or back of string and proceed to check
            if s[start] != s[end]:
                return palindrome(start, end-1, s) or palindrome(start+1, end, s)
            start += 1
            end -= 1
        return True
            