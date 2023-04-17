'''
Q633. Description: Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
'''

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        expected = int(c ** 0.5)
        low = 0
        high = expected

        while low <= high:
            temp = (low ** 2) + (high ** 2)

            if temp == c:
                return True
            elif temp < c:
                low += 1
            else:
                high -= 1
        return False