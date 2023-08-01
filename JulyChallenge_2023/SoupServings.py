'''
Q808. Description: There are two types of soup: type A and type B. Initially, we have n ml of each type of soup. There are four kinds of operations:

Serve 100 ml of soup A and 0 ml of soup B,
Serve 75 ml of soup A and 25 ml of soup B,
Serve 50 ml of soup A and 50 ml of soup B, and
Serve 25 ml of soup A and 75 ml of soup B.
When we serve some soup, we give it to someone, and we no longer have it. Each turn, we will choose from the four operations with an equal probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as possible. We stop once we no longer have some quantity of both types of soup.

Note that we do not have an operation where all 100 ml's of soup B are used first.

Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time. Answers within 10-5 of the actual answer will be accepted.
'''

class Solution:
    def soupServings(self, n: int) -> float:
        m = ceil(n/25)
        dp = {}

        # dp[i][j] means i servings of A and j servings of B
        def calculateDP(i, j):
            # Operation 1: dp[max(0,i−4)][j] : Reduce A by 4
            # Operation 2: dp[max(0, i - 3)][j - 1]: Reduce A by 3, B by 1
            # Operation 3: dp[max(0, i - 2)][max(0, j - 2)]: Reduce A, B by 2
            # Operation 4: dp[i - 1][max(0, j - 3)]: Reduce A by 1, B by 3

            return (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][j - 1] + 
                    dp[max(0, i - 2)][max(0, j - 2)] + dp[i - 1][max(0, j - 3)]) / 4
        
        # Both empty at same time has probability 1/2
        dp[0] = {0: 0.5}

        for k in range(1, m+1):
            dp[0][k] = 1
            dp[k] = {0: 0}

            for j in range(1, k + 1):
                dp[j][k] = calculateDP(j, k)
                dp[k][j] = calculateDP(k, j)
            
            if dp[k][k] > 1 - 1e-5:
                return 1
        
        return dp[m][m]