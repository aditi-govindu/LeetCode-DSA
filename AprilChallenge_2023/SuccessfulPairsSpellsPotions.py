'''
Q2300. Description: You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.
'''

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        ans = []
        for cost in spells:
            count = 0
            temp = [cost * i for i in potions]
            for val in temp:
                if  val >= success:
                    count += 1 
            ans.append(count)
        return ans

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        # Sort the potions array in increasing order.
        potions.sort()
        answer = []

        m = len(potions)
        maxPotion = potions[m - 1]

        for spell in spells:
            # Minimum value of potion whose product with current spell
            # will be at least success or more.
            minPotion = (success + spell - 1) // spell
            # Check if we don't have any potion which can be used.
            if minPotion > maxPotion:
                answer.append(0)
                continue
            # We can use the found potion, and all potion in its right
            # (as the right potions are greater than the found potion).
            index = bisect.bisect_left(potions, minPotion)
            answer.append(m - index)

        return answer