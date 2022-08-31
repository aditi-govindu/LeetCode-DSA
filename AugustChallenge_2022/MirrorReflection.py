'''
Q858. Description: There is a special square room with mirrors on each of the four walls. Except for the southwest corner, there are receptors on each of the remaining corners, numbered 0, 1, and 2.
The square room has walls of length p and a laser ray from the southwest corner first meets the east wall at a distance q from the 0th receptor.

Given the two integers p and q, return the number of the receptor that the ray meets first.
The test cases are guaranteed so that the ray will meet a receptor eventually.
'''
class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        # The least common multiple of 4 and 6 is 12, and 3x4 = 12, so the light will have to pass thru three walls before a multiple of 4 and a multiple of 6 coincide. 
        L = lcm(p, q)
        
    # In the mirrored room, the light would reflect off of three walls before hitting a corner, and three bounces bring us to receptor zero in the bottom right corner
        if (L//q)%2 == 0:
            return 2

        return (L//p)%2