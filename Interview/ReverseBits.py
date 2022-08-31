'''
Q190. Description: Reverse bits of a given 32 bits unsigned integer.
'''
class Solution:
    def reverseBits(self, n: int) -> int:
        return int('{:032b}'.format(n)[::-1], 2)