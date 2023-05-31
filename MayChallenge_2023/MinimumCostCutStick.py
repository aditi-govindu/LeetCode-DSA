'''
Q1547. Description: Given a wooden stick of length n units. The stick is labelled from 0 to n.
Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.
The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.
'''

class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        m = len(cuts)
        # Store cutting positions
        cuts = [0] + sorted(cuts) + [n]
        # Cost of cutting stick in 2 parts - left and right
        dp = [[0] * (m + 2) for _ in range(m + 2)]

        for diff in range(2, m+2):
            for left in range(m + 2 - diff):
                right = left + diff
                # If cut not possible, set to infinity
                ans = float('inf')
                for mid in range(left + 1, right):
                    ans = min(ans, dp[left][mid] + dp[mid][right] + cuts[right] - cuts[left])
                dp[left][right] = ans
        return dp[0][m+1]