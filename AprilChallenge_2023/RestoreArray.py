'''
Q1416. Description: A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits s and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.

Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program. Since the answer may be very large, return it modulo 109 + 7.
'''

class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        m, n = len(s), len(str(k))
        mod = 10 ** 9 + 7   
        dp = [0] * (m + 1)
        
        # Number of possible splits for s[start ~ m-1].
        def dfs(start):
            # If we have already updated dp[start], return it.
            if dp[start]:
                return dp[start]
            
            # There is only 1 split for an empty string.
            if start == m:
                return 1
            
            # Number can't have leading zeros.
            if s[start] == '0':
                return 0
            
            # For all possible starting number, add the number of arrays 
            # that can be printed as the remaining string to count.
            count = 0
            for end in range(start, m):
                curr_number = s[start: end + 1]
                if int(curr_number) > k:
                    break
                count += dfs(end + 1)
                
            # Update dp[start] so we don't recalculate it later.
            dp[start] = count % mod
            return count
        
        return dfs(0) % mod