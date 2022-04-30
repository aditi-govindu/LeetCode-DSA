'''
Q1046. Description: You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:
If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.

At the end of the game, there is at most one stone left.
Return the smallest possible weight of the left stone. If there are no stones left, return 0.
'''
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort(reverse=True)
        for i in range(len(stones) - 1):
            # If stone value greater than current value and it is not max limit, smash
            if stones[i] > stones[i+1] and stones[i] != 1001:
                # Update smaller value to remaining mass
                stones[i+1] = stones[i] - stones[i+1]
                # Update larger stone to smashed or 1001
                stones[i] = 1001
            elif stones[i] == stones[i+1]:
                # Update both stones to smashed or 1001
                stones[i] = 1001
                stones[i+1] = 1001
            # Sort in descending order
            stones.sort(reverse = True)
        if min(stones) == 1001:
            return 0
        return min(stones)