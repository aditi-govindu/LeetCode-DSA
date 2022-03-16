'''
Q190. Description: Reverse bits of a given 32 bits unsigned integer.
'''
class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0
        for i in range(32):
            # Bitwise left shift: Multiply number by power of 2
            res <<= 1
            # Add 0 if bits are not equal to 1
            res+=(n&1)
            # Bitwise right shift: Divide number by power of 2 and assign to n
            n >>= 1
        return res
        #return int('{:032b}'.format(n)[::-1], 2)