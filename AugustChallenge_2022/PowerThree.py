'''
Q326. Description: Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.
'''
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        # Math limitations: Max power of 3 of 32 bit length is 1162261467
        return n > 0 and 1162261467%n == 0