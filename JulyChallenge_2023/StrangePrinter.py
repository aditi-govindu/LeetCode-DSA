'''
Q664. Description: There is a strange printer with the following two special properties:

The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.
'''

class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        dp = [[n] * n for _ in range(n)]

        for length in range(1, n+1):
            for left in range(n - length + 1):
                right = left + length - 1

                # Check leftmost character with rightmost
                j = -1

                for i in range(left, right):
                    # Characters are different, hence set first letter
                    if s[i] != s[right] and j == -1:
                        j = i
                    if j != -1:
                        dp[left][right] = min(dp[left][right], 1 + dp[j][i] + dp[i+1][right])
                
                if j == -1:
                    dp[left][right] = 0
        
        # +1 due to first change not considered
        return dp[0][n-1] + 1