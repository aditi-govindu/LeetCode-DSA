'''
Q125. Description: A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
'''

class Solution:
    def isPalindrome(self, s: str) -> bool: 
        # Convert input to lowercase
        s = s.lower()
        string = ''
        for letter in s:
            # If letter is alphanumeric, add to string
            if letter.isalpha() or letter.isdigit():
                string+=letter
        # Compare all characters in string with reverse
        if string[:] == string[::-1]:
            return True
        else:
            return False
                