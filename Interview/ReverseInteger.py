'''
Q7. Description: Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
'''

class Solution:
    def reverse(self, x: int) -> int:
        temp = 1
        if x < 0:
            # Reverse the absolute value of x and multiply -1 if x < 0
            temp = -1
            x = abs(x)
        # Convert number to string, reverse and return int value
        reverse = temp * (int)(str(x)[::-1])
        # If reversed value is out of range, return 0
        if (reverse < ((-2) ** 31)) or reverse > ((2**31) - 1):
            return 0
        else:
            return reverse