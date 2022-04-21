'''
Q91. Description: A message containing letters from A-Z can be encoded into numbers using the following mapping: A-> 1, B -> 2 ... Z -> 26. 
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways).
Eg: 12 can be AB or L, hence return 2
'''

class Solution:
    def numDecodings(self, s: str) -> int:
        # Empty string initialize to 1
        dp = {len(s) : 1}
        
        def dfs(i):
            # End of string reached
            if i in dp:
                return dp[i]
            # 0 in front of numbers are not allowed. Eg: 06
            if s[i] == '0':
                return 0
            # For every index,w e can consider 1 number or 2
            res = dfs(i+1)
            # Ensure 2nd digit is valid
            if i+1 < len(s) and (s[i] == '1' or (s[i] == '2' and s[i+1] in '0123456')):
                res += dfs(i+2)
            dp[i] = res
            return res
        
        # Start from 0th index of string
        return dfs(0)