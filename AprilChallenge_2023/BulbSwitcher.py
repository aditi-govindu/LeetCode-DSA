'''
Q319. Description: Trick question!
There are n bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.

On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb.

Return the number of bulbs that are on after n rounds.
'''

import math
class Solution:
    def bulbSwitch(self, n: int) -> int:
        # Perfect square have odd no. of factors. Bulbs toggled at any point in time are odd
        
        # a perfect square number has an odd number of factors, 
        # since any number's factors come in pairs of two different numbers, 
        # but the square root of the number will be paired with itself.

        if n < 2:
            return n
        
        y = n
        z = (y + n/y) /2

        while abs(z - y) >= 0.01:
            y = z
            z = (y + n/y) / 2

        z = math.floor(z)
        return z