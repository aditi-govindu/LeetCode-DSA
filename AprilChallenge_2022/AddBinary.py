'''
Q67. Given two binary strings a and b, return their sum as a binary string.
'''

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # Convert to binary the sum of binary representation of both strings
        total = bin(int(a,2) + int(b,2))
        # First 2 characters are 0b, hence skipped
        return total[2:]