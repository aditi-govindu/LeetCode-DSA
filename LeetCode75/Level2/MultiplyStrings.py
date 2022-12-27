'''
Q43. Description: Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
'''

class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        n1 = (int)(num1)
        n2 = (int)(num2)
        return (str)(n1*n2)