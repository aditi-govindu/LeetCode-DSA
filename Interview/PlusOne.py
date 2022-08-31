""""
Q559. Description: You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
"""""

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        # Map converts multiple digits to original number. Eg: 1,2,3 -> 123. Increment number by 1
        number = (int)("".join(map(str, digits))) + 1
        # Return list of digits in number
        return [int(x) for x in str(number)]