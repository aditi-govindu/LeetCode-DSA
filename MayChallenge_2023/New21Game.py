'''
Q837. Description: Alice plays the following game, loosely based on the card game "21".

Alice starts with 0 points and draws numbers while she has less than k points. During each draw, she gains an integer number of points randomly from the range [1, maxPts], where maxPts is an integer. Each draw is independent and the outcomes have equal probabilities.

Alice stops drawing numbers when she gets k or more points.

Return the probability that Alice has n or fewer points.

Answers within 10-5 of the actual answer are considered accepted.
'''

class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        dp = [0] * (n + 1)
        dp[0] = 1

        # Set sliding window as initial point
        s = 1 if k > 0 else 0
        for i in range(1, n+1):
            # Set probability of all states from where i can be reached
            dp[i] = s / maxPts
            # If not yet reached k points, add to probability
            if i < k:
                s += dp[i]
            # If reached, subtract probability
            if i - maxPts >= 0 and i - maxPts < k:
                s -= dp[i - maxPts]
                    
        return sum(dp[k:])