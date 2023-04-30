'''
Q258. Description: Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
'''

class Solution:
    def addDigits(self, num: int) -> int:
        # Add digits in current number
        def Sum(n):
            single = 0
            while(n):
                dig = n%10
                single += dig
                n = n//10
            return single
        
        # Keep adding digits in number till single digit obtained
        ans = Sum(num)
        while(ans > 9):
            ans = Sum(ans)
        return ans
            