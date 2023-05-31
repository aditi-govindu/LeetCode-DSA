'''
Q1140. Description: Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.
'''

class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        # DP to keep track of states seen so far
        dp = [[[-1] * (n + 1) for i in range(n + 1)] for p in range(0, 2)]

        def f(p, i, m):
            # End of piles reached
            if i == n:
                return 0
            if dp[p][i][m] != -1:
                return dp[p][i][m]
            res = 1000000 if p == 1 else -1
            s = 0

            for x in range(1, min(2 * m, n - i) + 1):
                s += piles[i + x - 1]
                if p == 0:
                    # Alice choses 1,2,3...i+x-1 stones to maximize her value
                    res = max(res, s + f(1, i+x, max(m, x)))
                else:
                    # Bob choses same as Alice, but minimizes her score
                    res = min(res, f(0, i + x, max(m, x)))
            dp[p][i][m] = res
            return res
        
        # Alice moves first -> p = 0
        return f(0,0,1)