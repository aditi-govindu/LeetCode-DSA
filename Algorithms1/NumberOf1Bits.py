'''
Q191. Description: Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
'''
class Solution:
    def hammingWeight(self, n: int) -> int:
        # Get binary string and count no. of 1s
        binary = str(bin(n))
        return binary.count('1')
        