'''
Q1639. Description: You are given a list of strings of the same length words and a string target.

Your task is to form target using the given words under the following rules:

target should be formed from left to right.
To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
Repeat the process until you form the string target.
Notice that you can use multiple characters from the same string in words provided the conditions above are met.

Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.
'''

class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        mod = 10**9 + 7
        m = len(target)
        n = len(words)
        k = len(words[0])
        cnt = [[0]*k for i in range(26)]

        for j in range(k):
            for w in words:
                # Count no. of occurences of character c in jth column of matrix
                cnt[ord(w[j]) - ord('a')][j] += 1
        dp = [[0] * (k+1) for i in range(m+1)]
        dp[0][0] = 1

        for i in range(m+1):
            for j in range(k):
                # If i < m, pick current character and skip j column
                if i < m:
                    dp[i+1][j+1] += (cnt[ord(target[i]) - ord('a')][j] * dp[i][j]) 
                    dp[i+1][j+1] %= mod
                dp[i][j+1] += dp[i][j]
                dp[i][j+1] %= mod
        return dp[m][k]
        