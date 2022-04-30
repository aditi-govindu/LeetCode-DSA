'''
Q338. Description: Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
'''

class Solution:
    def countBits(self, n: int) -> List[int]:
        result = []
        # Consider all numbers in range 0 to n
        for i in range(n+1):
            # Convert to binary format
            number = str(bin(i))
            # Append count of 1's in every number to result
            result.append(number.count('1'))
            # Reset number to empty string
            number = ''
        return result  