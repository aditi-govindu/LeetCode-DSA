# Q50. Description: Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

class Solution:
    def myPow(self, x: float, n: int) -> float:
        # Border cases
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
            # If n is even, split powers and multiply 2 times
            if n&1:
                result *= x

            # Double base and half the power
            x*=x
            n = n//2
        return result