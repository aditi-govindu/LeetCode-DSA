'''
Q231. Description: Given an integer n, return true if it is a power of two. Otherwise, return false. An integer n is a power of two, if there exists an integer x such that n == 2x.
'''
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        # Convert number to binary format
        binary = str(bin(n))
        # Power of 2 will have exactly 1 occurence in binary string
        # Eg: 2^5 is 32, 2^1 is 2 while 3 is 2^1 + 2^0
        if binary.count('1') == 1 and n > 0:
            return True
        return False