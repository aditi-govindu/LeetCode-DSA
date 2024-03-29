'''
Q1406. Description: Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

Assume Alice and Bob play optimally.

Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.
'''

class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        not_computed = 10**9
        dp = [not_computed] * (n + 1)

        def f(i):
            # Base case
            if i == n:
                return 0
            # If computed previously, return answer
            if dp[i] != not_computed:
                return dp[i]

            # Consider 1 stone
            dp[i] = stoneValue[i] - f(i + 1)
            if i + 2 <= n:
                # Take 2 stones if larger
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] - f(i + 2))
            if i + 3 <= n:
                # Take 3 stones if even larger
                dp[i] = max(dp[i], stoneValue[i]+stoneValue[i+1] + stoneValue[i+2] - f(i+3))
            return dp[i]
        
        dif = f(0)
        if dif > 0:
            return 'Alice'
        if dif < 0:
            return 'Bob'
        return 'Tie'