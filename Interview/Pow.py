'''
Q50. Description: Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
'''

class Solution:
    def myPow(self, x: float, n: int) -> float:
        # Handling edge cases of power < 0, equal to 0,1,-1
        if n < 0:
            n = -n
            x = 1.0/x
        elif n == 0:
            return 1
        elif n == 1:
            return x
        elif n == -1:
            return 1.0/x
        result = 1.0
        while(n):
            # If n is even, split powers and multiple 2 times
            if n&1:
                result *= x
            x*=x
            # Reduce power by half
            n = n//2
        return result